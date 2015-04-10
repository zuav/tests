begin

  raise "string!"
rescue
  puts "got #{$!}"
  raise
end
