-module(ls).
-export([list_files/1]).

list_files(_Args) ->
    Port = open_port({spawn, "ls -l"}, [stream, exit_status, use_stdio]),
    loop(Port).

loop(Port) ->
    receive
        {Port, {data, Data}} ->
            io:format("~s", [Data]);
        {Port, {exit_status, Status}} ->
            io:format("process terminated with status: ~p~n", [Status])
    end.
