-module(copyfile).
-export([cp/2]).

cp(Source, Dest) ->
    {ok, Src} = file:open(Source, [read, binary, raw]),
    {ok, Dst} = file:open(Dest, [append, raw]),
    copy_loop(Src, Dst),
    file:close(Src),
    file:close(Dst).

copy_loop(Src, Dst) ->
    case file:read(Src, 64000) of
        {ok, Data} ->
            ok = file:write(Dst, Data),
            copy_loop(Src, Dst);
        eof ->
            ok
    end.
