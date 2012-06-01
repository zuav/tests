-module(tab).
-export([create_table/0, list_table/0]).

-record(person, {name, sex, age}).

create_table() ->
    L = [person_init(one, w, 1),
         person_init(two, m, 2),
         person_init(three, w, 3),
         person_init(four, m, 4)
        ],
    Tid = ets:new(person, [set, public, named_table, {keypos, 2}]),
    true = ets:insert(Tid, L),
    N = ets:info(Tid, size),
    io:format("number of records inserted: ~p~n", [N]).

list_table() ->
    L = ets:tab2list(person),
    io:format("~p~n", [L]).

person_init(Name, Sex, Age) ->
    #person{name=Name, sex=Sex, age=Age}.
