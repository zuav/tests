-module(define).
-export([f/0]).

%%-define(PREFIX, "prefix: ").

f() ->
    S = 1,
    io:format("~p: ~p~n", [?MODULE, S]).
