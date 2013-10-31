-module(function_name).
-export([show_name/0]).

show_name() ->
    [H|_] = process_info(self()),
    io:format("got: ~p~n", [H]).
