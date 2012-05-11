-module(ipaddr).
-export([string_to_integer/1, integer_to_string/1]).

-define(decode(A,B,C,D), (((A) bsl 24) bor
                              ((B) bsl 16) bor
                              ((C) bsl 8) bor
                              (D))).

-define(encode(N), {(((N) bsr 24) band 16#FF),
                    (((N) bsr 16) band 16#FF),
                    (((N) bsr 8) band 16#FF),
                    ((N) band 16#FF)}).



string_to_integer(S) ->
    {ok, {A, B, C, D}} = inet_parse:address(S),
    N = ?decode(A, B, C, D),
    io:format("IP as string:  ~s~nIP as integer: ~p~n", [S, N]).

integer_to_string(N) ->
    IpAddr = ?encode(N),
    S = inet_parse:ntoa(IpAddr),
    io:format("IP as string:  ~s~nIP as integer: ~p~n", [S, N]).

