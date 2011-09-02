-module(openfile).
-export([start/1]).

start(N) ->
    open_file(1, N).

open_file(N, N) ->
    do_open_file(N);
open_file(K, N) ->
    do_open_file(K),
    open_file(K+1, N).

do_open_file(N) ->
    Name = "/tmp/openfile." ++ integer_to_list(N),
    {ok, S} = file:open(Name, write),
    io:format("opened file number ~p~n", [N]),
    io:format(S, "~p~n", [N]).

