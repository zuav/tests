-module(flatmap).
-export([test/0]).

-record(rec, {num, elems}).

test() ->
    L = [#rec{num=1, elems=[1,2,3]},
         #rec{num=2, elems=[4,5,6]},
         #rec{num=3, elems=[7,8,9]}],

    F = fun(R) -> R#rec.elems end,

    LL = lists:flatmap(F, L),
    io:format("~p~n", [LL]).
