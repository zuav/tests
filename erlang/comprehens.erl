-module(comprehens).
-export([f/0]).

-record(block_data, {string, val}).
-record(block, {num, data}).


f() ->
    L = [#block{num=1, data=#block_data{string="1", val=91}},
         #block{num=2, data=#block_data{string="2", val=92}},
         #block{num=3, data=#block_data{string="3", val=93}},
         #block{num=4, data=#block_data{string="4", val=94}},
         #block{num=5, data=#block_data{string="5", val=95}},
         #block{num=6, data=#block_data{string="6", val=96}}],

    L1 = [{N, S} || #block{num=N, data=#block_data{string=S}} <- L],

    io:format("~p~n", [L1]).
