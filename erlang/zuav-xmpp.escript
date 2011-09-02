#!/usr/bin/env escript
%% -*- erlang -*-

-include_lib("exmpp/include/exmpp.hrl").
-include_lib("exmpp/include/exmpp_client.hrl").

-define(NS_DISCO, 'http://jabber.org/protocol/disco#info').

main([]) ->
    application:start(exmpp),
    Session = exmpp_session:start(),
    Jid = exmpp_jid:make("zuav", "localhost", random),
    LocalhostJid = exmpp_jid:make("localhost"),
    exmpp_session:auth_basic_digest(Session, Jid, "qwerty12"),
    {ok, _StreamId} = exmpp_session:connect_TCP(Session, "localhost", 5222),
    exmpp_session:login(Session),

    DiscoIq = exmpp_iq:get(undefined, exmpp_stanza:set_jids(exmpp_xml:element(?NS_DISCO, 'query'), Jid, LocalhostJid)),

    exmpp_session:send_packet(Session, DiscoIq),
    exmpp_session:send_packet(Session, exmpp_presence:set_status(exmpp_presence:available(), "zuav ready")),
    io:format("zuav ready sent.~n", []),

    loop().

loop() ->
    receive
        Record ->
            io:format("got stanza: ~p~n", [Record]),
            loop()
    after 5000 ->
            io:format("exiting~n", [])
    end.



    %% NS_TIME = 'urn:xmpp:time',
    %% NS_ITEMS = 'http://jabber.org/protocol/disco#items',
    %% GandalfJid = exmpp_jid:make("gandalf", "localhost"),

%% Iq = exmpp_iq:get(undefined, exmpp_stanza:set_jids(exmpp_xml:element(NS_TIME, 'time'), Jid, LocalhostJid)),
%% Iq = exmpp_iq:get(undefined, exmpp_stanza:set_jids(exmpp_xml:element(NS_ITEMS, 'query'), Jid, GandalfJid)),
%% exmpp_session:send_packet(Session, Iq),


