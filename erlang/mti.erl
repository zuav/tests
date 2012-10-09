-module(mti).
-export([create_table/0, list_table/0, find_user/1, ls_wallets/1]).
-include_lib("stdlib/include/qlc.hrl").

-record(rec, {
          key :: {string(), string()},
          val :: non_neg_integer()
         }).


create_table() ->
    Attrs = {attributes, record_info(fields, rec)},
    Type = {type, bag},
    {atomic, ok} = mnesia:create_table(rec, [Attrs, Type]),

    L = [#rec{key={"1", "1"}, val=111},
         #rec{key={"1", "1"}, val=111},
         #rec{key={"1", "2"}, val=121},
         #rec{key={"1", "2"}, val=122},
         #rec{key={"1", "2"}, val=123},
         #rec{key={"2", "1"}, val=211},
         #rec{key={"2", "1"}, val=212}],

    F = fun() -> lists:foreach(fun mnesia:write/1, L) end,
    mnesia:transaction(F).

list_table() ->
    F = fun() -> qlc:e(qlc:q([X || X <- mnesia:table(rec)])) end,
    {atomic, L} = mnesia:transaction(F),
    L.

find_user(User) ->
    F = fun() -> mnesia:match_object({rec, {User, '_'}, '_'}) end,
    {atomic, R} = mnesia:transaction(F),
    R.


ls_wallets(User) ->
    F = fun() -> mnesia:match_object(#rec{key={User, '_'}, val='_'}) end,
    {atomic, L} = mnesia:transaction(F),
    lists:map(fun(#rec{key={_, W}}) -> W end, L).
