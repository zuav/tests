-module(record_info).
-export([test/0]).

-record(test_rec, {name, field, ocean}).

test() ->
    %%RecordName = test_rec,
    %%io:format("record info: ~p~n", [record_info(fields, RecordName)]).
    io:format("record info: ~p~n", [record_info(fields, test_rec)]).
