-module(e1).
-export([f/1]).

f(V) when is_list(V) ->
    ok.
