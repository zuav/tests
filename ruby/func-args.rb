def foo(arg, hash = nil)
  puts "arg:  #{arg}"
  puts "hash: #{hash}"
end

foo(1, one: 1, two: 2, three: 3)
foo(2)
