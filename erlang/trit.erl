%%% tree in table

-module(trit).
-export([create_table/0, delete_table/0, clear_table/0, print_table/0,
         add_nodes/1, add_branch/2, find_branches/0,
         find_node_with_num/1]).

-record(node,   {hash, prev_hash, num_str, timestamp}).
-record(branch, {first, last, len=0, own_len=0, bp=[]}). % bp -- branch points


-define(TABLE, trit).


create_table() ->
    Attrs   = {attributes, record_info(fields, node)},
    RecName = {record_name, node},
    Index   = {index, [prev_hash]},
    Type    = {type, set},
    Copies  = {disc_only_copies, [node()]},
    {atomic, ok} =  mnesia:create_table(?TABLE, [Attrs, RecName, Index, Type, Copies]).


delete_table() ->
    {atomic, ok} = mnesia:delete_table(?TABLE).


clear_table() ->
    {atomic, ok} = mnesia:clear_table(?TABLE),
    ok.


print_table() ->
    F = fun() -> print_node(mnesia:first(?TABLE)) end,
    {atomic, ok} = mnesia:transaction(F),
    ok.


print_node('$end_of_table') ->
    ok;
print_node(Key) ->
    [Node] = mnesia:read(?TABLE, Key),
    io:format("~p : ~p~n", [Node#node.num_str, Node#node.hash]),
    print_node(mnesia:next(?TABLE, Key)).


add_nodes(N) when N >= 0 ->
    statistics(wall_clock),
    add_nodes(undefined, 0, N),
    {_, T} = statistics(wall_clock),
    Secs = T / 1000,
    io:format("added ~p nodes; elapsed time: ~p sec~n", [N, Secs]).

add_nodes(_, Lim, Lim) ->
    ok;
add_nodes(PrevHash, Num, Lim) ->
    Node = make_node(PrevHash, integer_to_list(Num)),
    ok = add_node(Node),
    add_nodes(Node#node.hash, Num+1, Lim).


add_branch(StartNum, Len) ->
    case find_node_with_num(StartNum) of
        not_found ->
            io:format("not found node with num: ~p~n", [StartNum]),
            ok;
        #node{prev_hash=PrevHash} ->
            add_branch_nodes(PrevHash, StartNum, 0, Len)
    end.

add_branch_nodes(_, _, Lim, Lim) ->
    ok;
add_branch_nodes(PrevHash, StartNum, Num, Lim) ->
    Str = StartNum ++ "-" ++ integer_to_list(Num),
    Node = make_node(PrevHash, Str),
    ok = add_node(Node),
    add_branch_nodes(Node#node.hash, StartNum, Num+1, Lim).


add_node(#node{hash=Hash, prev_hash=PrevHash} = Node) when is_record(Node, node) ->
    F = fun() ->
                case PrevHash of
                    undefined ->
                        case mnesia:index_read(?TABLE, PrevHash, #node.prev_hash) of
                            [] ->
                                mnesia:write(?TABLE, Node, write);
                            [_]  ->
                                mnesia:abort(duplicate_undefined)
                        end;
                    _  ->
                        case mnesia:read(?TABLE, PrevHash) of
                            [] ->
                                mnesia:abort(not_found_prev_hash);
                            [_]  ->
                                case mnesia:read(?TABLE, Hash) of
                                    [] ->
                                        mnesia:write(?TABLE, Node, write);
                                    [_] ->
                                        mnesia:abort(duplicate_hash)
                                end
                        end
                end
        end,
    {atomic, ok} = mnesia:transaction(F),
    ok.


make_node(PrevHash, Str) when is_list(Str) ->
    Timestamp=now(),
    Hash = make_node_hash(Str, Timestamp),
    #node{hash=Hash, prev_hash=PrevHash, num_str=Str, timestamp=Timestamp}.


make_node_hash(Str, {A,B,C}) ->
    L = [Str, integer_to_list(A), integer_to_list(B), integer_to_list(C)],
    crypto:sha(list_to_binary(L)).


find_node_with_num(Str) ->
    Pattern = #node{hash='_', prev_hash='_', num_str=Str, timestamp='_'},
    F = fun() -> mnesia:match_object(?TABLE, Pattern, read) end,
    case mnesia:transaction(F) of
        {atomic, [Node]} ->
            Node;
        [] ->
            not_found
    end.


%% -> [branch()]
find_branches() ->
    [Node] = find_node_with_prev_hash(undefined),
    Hash = Node#node.hash,
    Branch = #branch{first=Hash, last=Hash, len=1},
    place_next_node([Branch], []).


place_next_node([Trunk|Branches], FinishedBranches) ->
    PrevHash = Trunk#branch.last,
    case find_node_with_prev_hash(PrevHash) of
        [] ->
            place_next_node(Branches, [Trunk|FinishedBranches]);
        [Node|SpringNodes] ->
            NewLen = Trunk#branch.len + 1,
            NewOwnLen = Trunk#branch.own_len + 1,
            Hash = Node#node.hash,
            case length(SpringNodes) of
                0 ->
                    NewTrunk = Trunk#branch{last=Hash, len=NewLen, own_len=NewOwnLen},
                    place_next_node([NewTrunk|Branches], FinishedBranches);
                _ ->
                    NewBP = [PrevHash|Trunk#branch.bp],
                    NewTrunk = Trunk#branch{last=Hash, len=NewLen, own_len=NewOwnLen, bp=NewBP},
                    Springs = [branch_init(N#node.hash, NewLen, PrevHash) || N <- SpringNodes],
                    NewBranches = lists:append(Springs, Branches),
                    place_next_node([NewTrunk|NewBranches], FinishedBranches)
            end
    end
        ;
place_next_node([], FinishedBranches) ->
    FinishedBranches.


%%
%% -> [node()]
%%
find_node_with_prev_hash(PrevHash) ->
    F = fun() -> mnesia:index_read(?TABLE, PrevHash, #node.prev_hash) end,
    {atomic, Res} = mnesia:transaction(F),
    Res.


branch_init(Hash, Len, BranchPoint) ->
    #branch{first=Hash, last=Hash, len=Len, own_len=1, bp=[BranchPoint]}.
