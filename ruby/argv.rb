args = ARGV

puts "ARGV: #{ARGV}"
puts "args: #{args}"

#ARGV.delete(1)
#ARGV.delete(1)

puts "ARGV: #{ARGV}"
puts "args: #{args}"

args = ARGV.slice(1, ARGV.length)

puts "ARGV: #{ARGV}"
puts "args: #{args}"
