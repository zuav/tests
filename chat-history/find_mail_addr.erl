-module(find_mail_addr).

-export([find_mail_addr/2]).

find_mail_addr(User, Host) ->
    select_by_username(User, "email", "emails", Host).

select_by_username(User, Field, Table, Host) ->
    Query = "select " ++ Field ++ " from " ++ Table ++ " where username = '",
    case ejabberd_odbc:sql_query(Host, [Query, User, "';"]) of
        {selected, [Field], [{Value}]} ->
            Value;
        _ ->
            %% username or table doesn't exist
            Reason = "'" ++ Field ++ "' was not found for user '" ++ User ++ "' on host '" ++ Host ++ "'",
            erlang:error(Reason)
    end.
