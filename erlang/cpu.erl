-module(cpu).
-export([num_units/0]).

num_units() ->
    case erlang:system_info(cpu_topology) of
        undefined ->
            1;
        T ->
            L = length(T),
            [H|_] = T,
            L * num_units(H)
    end.


num_units({LevelTag, _InfoList, SubLevel}) ->
    num_units({LevelTag, SubLevel})
        ;
num_units({_LevelTag, {logical, _N}}) ->
    1
        ;
num_units({_LevelTag, SubLevel}) when is_list(SubLevel) ->
    L = length(SubLevel),
    [H|_] = SubLevel,
    L * num_units(H).


