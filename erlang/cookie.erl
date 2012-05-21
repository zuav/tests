-module(cookie).
-export([gimmy_cookie/0]).

-define(BYTE,          8/unsigned-big-integer).
-define(P3_COOKIE_LEN, 32).


gimmy_cookie() ->
    gimmy_cookie(?P3_COOKIE_LEN, <<>>).

gimmy_cookie(N, R) when N > 0 ->
    C = random:uniform(255),
    R1 = <<C:?BYTE, R/binary>>,
    gimmy_cookie(N-1, R1)
        ;
gimmy_cookie(0, R) ->
    R.
