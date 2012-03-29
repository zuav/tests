-module(win_service).
-author(zuav).

-define(FILENAME, "/tmp/win-service.txt").

-export([start/0, stop/0]).

start()->
    {ok, S} = file:open(?FILENAME, write),
    Pid = spawn(fun() -> loop(S) end),
    io:format(S, "loop started, pid: ~p; at time: ~p~n", [Pid, time()]),
    true = register(?MODULE, Pid).

stop() ->
    ?MODULE ! stop.

loop(S) ->
    receive
        stop ->
            io:format(S, "got 'stop' command, exiting~n", [])
    after 5000 ->
            io:format(S, "ping ~p~n", [time()]),
            loop(S)
    end.
