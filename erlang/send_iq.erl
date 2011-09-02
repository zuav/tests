#!/usr/bin/env escript

main([]) ->
    application:start(exmpp),
    Session = exmpp_session:start(),
    Jid = exmpp_jid:make("zuav", "bakery.ithilien.unison.local"),
    GandalfJid = exmpp_jid:make("gandalf", "bakery.ithilien.unison.local"),
    exmpp_session:auth_basic_digest(Session, Jid, "qwerty12"),
    P = exmpp_presence:subscribe(),
    P1 = exmpp_stanza:set_sender(P, Jid),
    P2 = exmpp_stanza:set_recipient(P1, GandalfJid),
    P3 = exmpp_stanza:set_id(P2, random),
    {ok, _StreamId} = exmpp_session:connect_TCP(Session, "im.ithilien.unison.local", 5222),
    exmpp_session:login(Session),
    exmpp_session:send_packet(Session, P3),
    exmpp_session:stop(Session).
