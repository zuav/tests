-module(nested_include).

-include("nested.hrl").
-include("siprecords.hrl").
-include_lib("kernel/include/file.hrl").

-export([func/0]).

func() ->
    io:format("from level 1: ~p~n", [?LEVEL_1]),
    io:format("from level 2: ~p~n", [?LEVEL_2]),
    ok.
