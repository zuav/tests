-module(listen_udp).

-export([listen/0]).

listen() ->
    {ok, Socket} = gen_udp:open(7777),
    {ok, {Address, Port, Packet}} = gen_udp:recv(Socket, 50),

