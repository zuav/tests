-module(makedep).

-export([run/1]).

run(FileName) ->
    {ok, L} = epp:parse_file(FileName, [".", "/usr/local/lib/yxa/include"], []),
    RDL = lists:foldl(fun(E, Acc) -> is_include_file(E, Acc) end, [], L),
    %% first element is FileName itself
    [_|DL] = lists:reverse(RDL),
    print(DL).

is_include_file({attribute, 1, file, {Name, 1}}, Acc) ->
    [Name | Acc];
is_include_file(_, Acc) ->
    Acc.

print([]) ->
    ok;
print([H|T]) ->
    io:format("~s~n", [H]),
    print(T).
