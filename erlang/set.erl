-module(set).
-export([test/0]).

-record(pair, {str, num}).

test() ->
    mnesia:start(),
    mnesia:create_table(pair, [{ram_copies, [node()]}, {attributes, record_info(fields, pair)}, {type, set}]),

    add_recs(),
    show_recs(),
    delete_rec("four"),
    show_recs(),

    mnesia:delete_table(pair),
    mnesia:stop().

add_recs() ->
    F = fun() ->
                mnesia:write(#pair{str="one",   num=1}),
                mnesia:write(#pair{str="two",   num=2}),
                mnesia:write(#pair{str="three", num=3}),
                mnesia:write(#pair{str="four",  num=4}),
                mnesia:write(#pair{str="five",  num=5})
        end,
    case mnesia:transaction(F) of
        {atomic, _} ->
            io:format("set: added records successfully~n", []);
        {aborted, Reason} ->
            io:format("set: failed to add records; reason: ~p~n", [Reason]),
            exit(Reason)
    end.

show_recs() ->
    F = fun() ->
                A = fun(R, Acc) -> [R|Acc] end,
                L = mnesia:foldl(A, [], pair),
                io:format("set: record in the table are: ~n", []),
                lists:foreach(fun(E) -> io:format("    ~p~n", [E]) end, L),
                io:format("~n", [])
        end,
    case mnesia:transaction(F) of
        {atomic, _} ->
            ok;
        {aborted, Reason} ->
            io:format("set: failed to show records; reason: ~p~n", [Reason]),
            exit(Reason)
    end.

delete_rec(S) ->
    F = fun() -> mnesia:delete({pair, S}) end,
    case mnesia:transaction(F) of
        {atomic, _} ->
            io:format("set: record with key ~s deleted successfully~n", [S]);
        {aborted, Reason} ->
            io:format("set: failed to delete record with key ~s; reason: ~p~n", [S, Reason]),
            exit(Reason)
    end.
