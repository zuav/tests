-module(test).
-export([string_to_int/1,
         badsend/0,
         run/2,
         compare/1,
         check_element/1,
         return_empty_list/0]).

string_to_int(S) ->
    list_to_integer(S).


badsend() ->
    popa ! data.

run(Cmd, _Tries) ->
    Port = open_port({spawn, Cmd}, [stream, exit_status, use_stdio]),
    receive
        {Port, {exit_status, Status}} ->
            io:format("Exit with status: ~p~n", [Status])
    end.
    %%Port ! {command, zzz}.

compare(Val) ->
    if
        Val == true ->
            io:format("Val == true~n", []);
        true ->
            io:format("Val != true~n", [])
    end,
    io:format("Val: ~p~n", [Val]).


check_element(E) ->
    case E of
        foo ->
            foo;
        bar ->
            bar
    end.

return_empty_list() ->
    [].
