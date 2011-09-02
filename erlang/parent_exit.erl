-module(parent_exit).

-export([start/0]).

start() ->
    Pid = spawn(fun parent/0),
    io:format("parent pid: ~p~n", [Pid]),
    Pid.

parent() ->
    process_flag(trap_exit, true),
    Pid = spawn_link(fun child/0),
    io:format("child pid: ~p~n", [Pid]),
    timer:sleep(2000),
    io:format("parent will exit now~n", []),
    exit(Pid, stop),
    ok.

child() ->
    timer:sleep(1200000),
    io:format("parent will exit now~n", []),
    ok.

