-module(inttohex).
-export([convert/1]).

convert(0) ->
    "0";
convert(I) ->
    convert_i(I).

convert_i(0) ->
    "";
convert_i(I) ->
    convert_i(I div 16) ++ hexdigit(I rem 16).

hexdigit(0)  -> "0";
hexdigit(1)  -> "1";
hexdigit(2)  -> "2";
hexdigit(3)  -> "3";
hexdigit(4)  -> "4";
hexdigit(5)  -> "5";
hexdigit(6)  -> "6";
hexdigit(7)  -> "7";
hexdigit(8)  -> "8";
hexdigit(9)  -> "9";
hexdigit(10) -> "A";
hexdigit(11) -> "B";
hexdigit(12) -> "C";
hexdigit(13) -> "D";
hexdigit(14) -> "E";
hexdigit(15) -> "F".
