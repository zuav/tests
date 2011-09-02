-module(rec_fun_match).

-export([check/0]).

-record(rec, {one, two, three}).

check() ->
    R1 = #rec{one="one", two="2-r1", three="3-r1"},
    check(R1).

check(#rec{one="one", two=Two} = R) ->
    io:format("two: ~p; R = ~p~n", [Two, R]).
