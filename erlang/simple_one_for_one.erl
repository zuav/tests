-module(simple_one_for_one).
-author(zuav).
-behaviour(supervisor).

-export([start_link/0, start_worker/3]).
-export([init/1]).

start_link() ->
    supervisor:start_link({local, ?MODULE}, ?MODULE, []).

start_worker(Pid, Num, Name) ->
    supervisor:start_child(Pid, [[Num, Name]]).

init([]) ->
    Elem = {simple_one_for_one_proc, {simple_one_for_one_proc, start_link, []}, transient, brutal_kill, worker, [simple_one_for_one_proc]},
    Children = [Elem],
    RestartStrategy = {simple_one_for_one, 50, 10},
    {ok, {RestartStrategy, Children}}.
