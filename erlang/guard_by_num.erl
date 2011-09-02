-module(guard_by_num).
-export([foo/1]).

foo(N) when N > 0  -> io:format("Param is more than zero: ~p~n", [N]);
foo(N)             -> io:format("Param is less or equal than zero: ~p~n", [N]).
