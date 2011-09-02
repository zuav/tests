-module(fileinfo).
-export([info/1]).

-include_lib("kernel/include/file.hrl").

info(FileName) ->
    {ok, _Fd} = file:open(FileName, [append, raw]),
    {ok, FileInfo} = file:read_file_info(FileName),
    io:format("FileInfo for File ~p:  ~p\n", [FileName, FileInfo]),
    Mode = 8#00400 + 8#00200 + 8#00040,
    FileInfo1 = FileInfo#file_info{mode=Mode},
    ok = file:write_file_info(FileName, FileInfo1),
    {ok, FileInfo2} = file:read_file_info(FileName),
    io:format("FileInfo2 for File ~p: ~p\n", [FileName, FileInfo2]).
    
