#!/usr/bin/env escript
%% -*- erlang -*-

-include_lib("exmpp/include/exmpp.hrl").
-include_lib("exmpp/include/exmpp_client.hrl").


main([]) ->
    application:start(exmpp),
    Session = exmpp_session:start(),
    Jid = exmpp_jid:make("gandalf", "middleearth", random),
    exmpp_session:auth_basic_digest(Session, Jid, "qwerty12"),
    {ok, _StreamId} = exmpp_session:connect_TCP(Session, "localhost", 5222),
    session(Session, Jid).

session(Session, _Jid) ->
    try exmpp_session:login(Session)
    catch
	throw:{auth_error, 'not-authorized'} ->
            io:format("auth error~n", []),
            exit("Auth error")
    end,

    exmpp_session:send_packet(Session, exmpp_presence:set_status(exmpp_presence:available(), "Gandalf Ready")),
    io:format("Gandalf ready.~n", []),

    loop(Session).

loop(Session) ->
    receive
        stop ->
            exmpp_session:stop(Session);
        Record = #received_packet{packet_type=message, raw_packet=Packet} ->
            io:format("got message: ~p~n", [Record]),
            echo_packet(Session, Packet),
            loop(Session);
        Record ->
            io:format("got stanza: ~p~n", [Record]),
            loop(Session)
    end.

echo_packet(Session, Packet) ->
    From = exmpp_xml:get_attribute(Packet, from, <<"unknown">>),
    To = exmpp_xml:get_attribute(Packet, to, <<"unknown">>),
    TmpPacket = exmpp_xml:set_attribute(Packet, from, To),
    TmpPacket2 = exmpp_xml:set_attribute(TmpPacket, to, From),
    NewPacket = exmpp_xml:remove_attribute(TmpPacket2, id),
    exmpp_session:send_packet(Session, NewPacket).
