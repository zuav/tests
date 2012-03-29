-module(macro).

-export([print/0]).

print() ->
    io:format("?MODULE: ~p~n", [?MODULE]).
