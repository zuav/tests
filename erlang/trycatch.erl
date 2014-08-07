-module(trycatch).
-export([foo/0]).

foo() ->
    try
        io:format("1~n", []),
        10 = io:format("2~n", [])
    catch
        Tag:Reason ->
            io:format("error: ~p:~p~n", [Tag, Reason])
    end.
