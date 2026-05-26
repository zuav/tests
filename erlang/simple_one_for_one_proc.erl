-module(simple_one_for_one_proc).
-author(zuav).
-behaviour(gen_server).


-export([start_link/1]).
-export([init/1, handle_call/3, handle_cast/2, handle_info/2, terminate/2, code_change/3]).


-record(state, {
          num,
          name
         }).



start_link(Args) ->
    gen_server:start_link(?MODULE, Args, []).


init([Num, Name]) ->
    io:format("worker number ~p started with name: ~p~n", [Num, Name]),
    {ok, #state{num=Num, name=Name}, 0}.


handle_call(_Request, _From, State) ->
    {reply, ignored, State}.


handle_cast(_Request, State) ->
    {noreply, State}.


handle_info(timeout, #state{num=Num, name=Name} = State) ->
    io:format("~p:~p: -- bip~n", [Num, Name]),
    {noreply, State, 10000}
        ;
handle_info(_Info, State) ->
    {noreply, State}.


terminate(Reason, #state{num=Num, name=Name}) ->
    io:format("worker number ~p with name ~p terminated with reason: ~p~n", [Num, Name, Reason]),
    ok.


code_change(_OldVsn, State, _Extra) ->
    {ok, State}.
