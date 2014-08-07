-module(case_test).
-export([check_element/1, string_case/1]).

check_element(E) ->
    case E of
        foo ->
            foo;
        bar ->
            bar
    end.


string_case(Str) ->
    case Str of
        "qos: " ++ _ ->
            io:format("qos string: ~s~n", [Str]);
        "x264extra: " ++ _ ->
            io:format("x264extra string: ~s~n", [Str]);
        _ ->
            io:format("unknown string: ~s~n", [Str])
    end,
    ok.
