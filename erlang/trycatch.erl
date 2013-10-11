-module(trycatch).
-export([foo/0]).

foo() ->
    try
        %%Str = "String",
        io:format("1~n", []),
        10 = io:format("2~n", [])
    catch
        Tag:Reason ->
            %%io:format("~p: exception: ~p~nreason: ~p~n", [String, Tag, Reason])
            io:format("~p: exception: ~p~nreason: ~p~n", [Tag, Reason])
    end.
