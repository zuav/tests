#!/usr/bin/env ruby

case ARGV[0]
when "bla"
  var = 1
  puts 1
when "blabla"
  var = 2
  puts 2
else
  var = 3
  puts "No bla!"
end

puts "var = #{var}"
