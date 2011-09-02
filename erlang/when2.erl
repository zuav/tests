-module(when2).
-export([f/2]).

f(A, B) when ((A =:= 1) orelse ( A =:= 2)) andalso (B =:= 3) ->
    io:format("first clause: A: ~p, B: ~p~n", [A, B]);
f(A, B) when B =:= 3->
    io:format("second clause: A: ~p, B: ~p~n", [A, B]).
