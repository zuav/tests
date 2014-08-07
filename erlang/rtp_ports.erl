-module(rtp_ports).

-export([four/2, four/3]).

four(Start, Num) ->
    four(Start, 1,  Num).

four(_, N, Lim)  when N > Lim ->
    io:format("~n");
four(Start, N, Lim) ->
    P0 = Start + (N - 1) * 8,
    P1 = Start + (N - 1) * 8 + 2,
    P2 = Start + (N - 1) * 8 + 4,
    P3 = Start + (N - 1) * 8 + 6,
    io:format("~2p: ~4p, ~4p, ~4p, ~4p~n", [N, P0, P1, P2, P3]),
    four(Start, N+1, Lim).
