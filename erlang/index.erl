-module(index).
-export([of_element/2]).

%%
%% of_element(List, Value) -> Integer | false
%%
%% of_element(["foo", "bar", "bas"], "bar") -> 1
%% of_element(["foo", "bar", "bas"], "xyz") -> false
%%
of_element(List, Value) ->
    is_nth(List, Value, 0).

is_nth([], _, _) ->
    false;
is_nth([H|T], Value, N) ->
    case H == Value of
        true ->
            N;
        false ->
            is_nth(T, Value, N+1)
    end.
