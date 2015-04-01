foo = Hash.new([])
bar = { one: 1, two: -1, three: -1 }

bar.each_key { |key| puts "bar[#{key}] = #{bar[key]}" }

bar.each_key do |key|
  if bar[key] > 0
    foo[key] = foo[key] << [19, bar[key]]
  end
end

foo.each_key { |key| puts "foo[#{key}] = #{foo[key]}" }
