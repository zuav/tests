-module(mnq).
-export([create_table/0, clear_table/0, list_table/0, find_rec_with/2, update_conn_time/2]).
-include_lib("stdlib/include/qlc.hrl").

-record(neighbour_srv, {
          addr            :: string(),
          port            :: non_neg_integer(),
          last_conn_time  :: erlang:timestamp(),
          creation_time   :: erlang:timestamp()
         }).


create_table() ->
    Attrs = {attributes, record_info(fields, neighbour_srv)},
    Type = {type, set},
    {atomic, ok} = mnesia:create_table(neighbour_srv, [Attrs, Type]),

    L = [{neighbour_srv, "10.77.9.52", 7771, {0,0,0}, now()},
         {neighbour_srv, "10.77.9.53", 7772, {0,0,0}, now()},
         {neighbour_srv, "10.77.9.54", 7773, {0,0,0}, now()}
        ],
    F = fun() -> lists:foreach(fun mnesia:write/1, L) end,
    mnesia:transaction(F).

clear_table() ->
    mnesia:clear_table(neighbour_srv).

list_table() ->
    F = fun() -> qlc:e(qlc:q([X || X <- mnesia:table(neighbour_srv)])) end,
    {atomic, L} = mnesia:transaction(F),
    L.
    
find_rec_with(Addr, Port) ->
    F = fun() ->
                qlc:e(qlc:q([X || X <- mnesia:table(neighbour_srv),
                                  X#neighbour_srv.addr =:= Addr,
                                  X#neighbour_srv.port =:= Port]))
        end,
    {atomic, [R]} = mnesia:transaction(F),
    R.

update_conn_time(Addr, Port) ->
    F = fun() ->
                case qlc:e(qlc:q([X || X <- mnesia:table(neighbour_srv),
                                       X#neighbour_srv.addr =:= Addr,
                                       X#neighbour_srv.port =:= Port])) of
                    [R] ->
                        mnesia:write(R#neighbour_srv{last_conn_time=now()});
                    [] ->
                        Neib = #neighbour_srv{addr=Addr, port=Port, last_conn_time=now(), creation_time=now()},
                        mnesia:write(Neib)
                end
        end,
    {atomic, ok} = mnesia:transaction(F),
    ok.
