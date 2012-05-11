-module(keymember_guard).
-record(rec, {str, dig}).

-export([build_list/0, test/2]).

build_list() ->
    [#rec{str="One",   dig=1},
     #rec{str="Two",   dig=2},
     #rec{str="Three", dig=3}].

%% doesn't compiles:
%%
%% test(L) when lists:keymember(3, 2, L) ->
%%     ok.

test(L, Key) ->
    io:format("str pos num: ~p~n", [#rec.str]),
    V = lists:keymember(Key, 3, L),
    if 
        V  ->
            ok;
        true ->
            failed
    end.
