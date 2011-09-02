-module(map).
-export([test/0]).

format_company({fss_company, Id, Name}) ->
    io:format("Id: ~p~nName: ~p~n", [Id, Name]).

test() ->
    F = fun(X) -> format_company(X) end,
    lists:map(F, [{fss_company, 1, "sdf"}, {fss_company, 2, "abc"}]).

