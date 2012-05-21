-module(ipaddr).
-export([string_to_integer/1, integer_to_string/1, int_to_str/1]).

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
    NetBin = <<N:32/unsigned-big-integer>>,
    <<H:32/unsigned-little-integer>> = NetBin,
    io:format("IP as string:                  ~s~n"
              "IP as integer (host order):    ~p~n"
              "IP as integer (network order): ~p~n", [S, N, H]).

integer_to_string(N) ->
    IpAddr = ?encode(N),
    S = inet_parse:ntoa(IpAddr),
    io:format("IP as string:  ~s~nIP as integer: ~p~n", [S, N]).

int_to_str(N) ->
    ?encode(N).
