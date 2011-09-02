-module(catchme).
-export([foo/0]).

foo() ->
    try
        baz(atom),
        bar(),
        bav()
    catch
        _:R ->
            io:format("got error with reason: ~p; ~p~n", [R, erlang:get_stacktrace()])
    end.

baz([_|_]) ->
    io:format("baz()~n", []).

bav() ->
    io:format("bav()~n", []).

bar() ->
    erlang:error("Because").
