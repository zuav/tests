#!/usr/bin/env escript
%% -*- erlang -*-

-include_lib("exmpp/include/exmpp.hrl").
-include_lib("exmpp/include/exmpp_client.hrl").


main([]) ->
    application:start(exmpp),
    Session = exmpp_session:start(),
    Jid = exmpp_jid:make("bilbo", "middleearth", random),
    exmpp_session:auth_basic_digest(Session, Jid, "qwerty12"),
    {ok, _StreamId} = exmpp_session:connect_TCP(Session, "localhost", 5222),
    exmpp_session:login(Session),

    exmpp_session:send_packet(Session, exmpp_presence:set_status(exmpp_presence:available(), "Bilbo Ready")),
    io:format("bilbo ready.~n", []),

    loop().

loop() ->
    receive
        Record ->
            io:format("got stanza: ~p~n", [Record]),
            loop()
    after 50000 ->
            io:format("exiting~n", [])
    end.
