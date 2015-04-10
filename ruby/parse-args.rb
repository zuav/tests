ARGV.each do |opt|
  case opt
  when /^--target-os=(\w+)/
    puts "target os: #{$1}"
  else
    puts "unknown option: #{opt}"
  end
end
