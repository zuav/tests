-module(factorial).
-export([fact1/1, fact2/1]).

fact1(0) ->
    1;
fact1(1) ->
    1;
fact1(N) ->
    N * fact1(N-1).


fact2(N) ->
    factorial(1, N, 1).

factorial(N, N, R) when N > 0 ->
    N * R;
factorial(K, N, R) when N > 0, K > 0, K < N ->
    factorial(K+1, N, K*R).

