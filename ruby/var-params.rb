def foo(*params)
  puts "foo params: #{params}"
end

def bar(*params)
  puts "bar params: #{params}"
  foo(*params)
end

bar 1, 2, 3
