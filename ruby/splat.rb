def f1(a1, *args)
  puts "f1 a1 = #{a1}"
  puts "f1 args: #{args}"

  f2(a1, *args)
end

def f2(*args)
  puts "f2 args: #{args}"
end

f1(1, 2, 3)
