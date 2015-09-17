-- main = interact wordCount where wordCount input = show (length (lines input)) ++ "\n"
-- main = interact wordCount where wordCount input = show (length (words input)) ++ "\n"
main = interact wordCount where wordCount input = show (length input) ++ "\n"
