-module(oneport).

-export([server/3, client/4, client_send_loop/4]).

server(Port, ClientHost, ClientPort) ->
    {ok, Socket} = gen_udp:open(Port, [binary, {active, false}, {reuseaddr, true}]),
    io:format("server: opened socket: ~p~n", [Socket]),
    server_loop(Socket, ClientHost, ClientPort),
    ok.

client(Port, SrvHost, SrvPort, Limit) ->
    {ok, Socket} = gen_udp:open(Port, [binary, {active, false}, {reuseaddr, true}]),
    io:format("client: opened socket: ~p~n", [Socket]),
    spawn(?MODULE, client_send_loop, [Socket, Limit, SrvHost, SrvPort]),
    client_recv_loop(Socket, Limit),
    ok.

server_loop(Socket, ClientHost, ClientPort) ->
    {ok, {Address, Port, <<Num:32>>}} = gen_udp:recv(Socket, 256, 60000),
    io:format("server: got from ~p:~p: ~p~n", [Address, Port, Num]),
    Num1 = Num + 1,
    Packet1 = <<Num1:32>>,
    ok = gen_udp:send(Socket, ClientHost, ClientPort, Packet1),
    io:format("server: sent: ~p~n", [Num1]),
    case Num > 0 of
        false ->
            io:format("server: exiting~n", []),
            ok;
        true ->
            server_loop(Socket, ClientHost, ClientPort)
    end.

client_send_loop(Socket, Limit, SrvHost, SrvPort) ->
    Packet = <<Limit:32>>,
    ok = gen_udp:send(Socket, SrvHost, SrvPort, Packet),
    io:format("client_send: sent: ~p~n", [Limit]),
    case Limit > 0 of
        false ->
            io:format("client_send: exiting; Num: ~p~n", [Limit]);
        true ->
            client_send_loop(Socket, Limit-2, SrvHost, SrvPort)
    end.

client_recv_loop(Socket, Limit) ->
    case Limit > 0 of
        false ->
            io:format("client_recv: exiting; Num: ~p~n", [Limit]);
        true ->
            {ok, {Address, Port, <<Num:32>>}} = gen_udp:recv(Socket, 256, 10000),
            io:format("client_recv: got from ~p:~p: ~p~n", [Address, Port, Num]),
            client_recv_loop(Socket, Limit-2)
    end.

