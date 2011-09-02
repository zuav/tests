-module(run_proc).
-export([start/2, stop/0, send_string/1]).

-define(PROC_ATOM_NAME, external_proc).
-define(PROC_CMD_NAME,  "/home/zuav/src/utils/z-read-cin").

start(Args, Attempts) ->
    Command = build_command(?PROC_CMD_NAME, Args),
    io:format("Command: ~p~n", [Command]),
    spawn(fun() ->
                  register(?PROC_ATOM_NAME, self()),
                  process_flag(trap_exit, true),
                  Port = run_command(Command, 1),
                  loop(Command, Port, 1, Attempts)
          end).

stop() ->
    ?PROC_ATOM_NAME ! stop.

send_string(Message) ->
    ?PROC_ATOM_NAME ! {call, self(), Message}.
    

build_command(Cmd, Args) ->
    Cmd ++ build_command1(Args, "").

build_command1([], Res) ->
    Res;
build_command1([H|T], Res) ->
    Res1 = Res ++ " " ++ H,
    build_command1(T, Res1).

run_command(Cmd, Num) ->
    io:format("trying to run command~n"
              "    Cmd: ~s~n"
              "    Num: ~p~n",
              [Cmd, Num]),
    open_port({spawn, Cmd}, [stream, exit_status, use_stdio]).

loop(Command, Port, Num, Attempts) ->
    receive
        {call, _, Msg} ->
            Port ! {self(), {command, Msg}},
            loop(Command, Port, 1, Attempts);
        stop ->
            Port ! {self(), close},
            receive
                {Port, closed} ->
                    exit(normal)
            end;
        {Port, {exit_status, Status}} ->
            sleep(1000),
            io:format("got exit_status with status: ~p~n", [Status]),
            if
                Num =< Attempts ->
                    Port1 = run_command(Command, Num),
                    loop(Command, Port1, Num + 1, Attempts);
                true ->
                    io:format("terminating loop~n"
                              "  Attempts: ~p~n"
                              "  Num:      ~p~n"
                              "  Status:   ~p~n",
                              [Attempts, Num, Status]),
                    exit({process_terminated, Status})
            end;
        {'EXIT', Port, Reason} ->
            sleep(1000),
            io:format("Port process exited with code: ~p~n", [Reason]),
            if
                Num =< Attempts ->
                    Port1 = run_command(Command, Num),
                    loop(Command, Port1, Num + 1, Attempts);
                true ->
                    io:format("terminating loop~n"
                              "  Attempts: ~p~n"
                              "  Num:      ~p~n"
                              "  Reason:   ~p~n",
                              [Attempts, Num, Reason]),
                    exit({port_terminated, Reason})
            end
    end.

sleep(T) ->
    receive
    after T ->
            true
    end.
