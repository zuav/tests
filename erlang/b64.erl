-module(b64).
-export([base64_encode/1]).

base64_encode(Text) ->
    base64_encode(base64:encode_to_string(Text), 77, 1).

base64_encode([], _, _) ->
    [];
base64_encode([H|T], BoundPos, BoundPos) ->
    [H, 13, 10 | base64_encode(T, BoundPos, 1)];
base64_encode([H|T], BoundPos, Counter) ->
    [H | base64_encode(T, BoundPos, Counter + 1)].
