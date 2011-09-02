-module(gen_fsm_1).
-behaviour(gen_fsm).

-export([start_link/0, start/0]).
-export([init/1, handle_event/3, handle_info/3, terminate/3, work/2, work/3]).

start_link() ->
    gen_fsm:start_link(?MODULE, [], []).

start() ->
    gen_fsm:start(?MODULE, [], []).

init([]) ->
    {ok, work, []}.

handle_event(Event, StateName, StateData) ->
    io:format("handle_event got: event: ~p, in state: ~p~n", [Event, StateName]),
    {next_state, StateName, StateData}.

handle_info(Event, StateName, StateData) ->
    io:format("handle_info got: event: ~p, in state: ~p~n", [Event, StateName]),
    {next_state, StateName, StateData}.

terminate(_Reason, _StateName, _StateData) ->
    ok.

work(Event, StateData) ->
    io:format("work/2 got: event: ~p~n", [Event]),
    {next_state, work, StateData}.

work(Event, From, StateData) ->
    io:format("work/3 got: event: ~p; from: ~p~n", [Event, From]),
    {next_state, work, StateData}.

