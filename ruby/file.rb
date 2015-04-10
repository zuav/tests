require 'pathname'

puts __FILE__
puts File.dirname(__FILE__)
puts Pathname.new(File.dirname(__FILE__)).parent.join('crew')
