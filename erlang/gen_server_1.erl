-module('gen_server_1').
-behaviour(gen_server).


-export([start_link/0, start/0, stop/0]).
-export([init/1, handle_call/3, handle_cast/2, handle_info/2, terminate/2, code_change/3]).


-define(SERVER, ?MODULE).


-record(state, {}).


start_link() ->
    gen_server:start_link({local, ?SERVER}, ?MODULE, [], []).

start() ->
    gen_server:start_link(?MODULE, [], []).

stop() ->
    gen_server:call(?MODULE, stop).

init([]) ->
    {ok, #state{}}.

handle_call(stop, _From, State) ->
    io:format("handle_call/3: got request: stop~n", []),
    {stop, normal, stopped, State};

handle_call(Request, _From, State) ->
    io:format("handle_call/3: got request: ~p~n", [Request]),
    Reply = ok,
    {reply, Reply, State}.


handle_cast(Msg, State) ->
    io:format("handle_cast/2: got message: ~p~n", [Msg]),
    {noreply, State}.

handle_info(Info, State) ->
    io:format("handle_info/2: got info: ~p~n", [Info]),
    {noreply, State}.

terminate(_Reason, _State) ->
    ok.

code_change(_OldVsn, State, _Extra) ->
    {ok, State}.
