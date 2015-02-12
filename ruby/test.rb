module A

  V1 = 1
  V2 = V1 + 1

  def self.foo
    puts "V1 = #{V1}"
    puts "V2 = #{V2}"
    puts "V3 = #{V3}"
  end

  V3 = V2 + 1
end

puts "V1 = #{A::V1}"
puts "V2 = #{A::V2}"
puts "V3 = #{A::V3}"

A.foo

# class A
#   def self.foo
#     puts "method foo from module A called"
#   end
# end

# class B
#   include A

#   def self.bar
#     A.foo
#   end
# end

# B.bar


# module A
#   def self.foo
#     puts "method foo from module A called"
#   end
# end

# module B
#   include A

#   def self.bar
#     A.foo
#   end

#   def baz
#     puts "instance method baz"
#   end
# end

# B.bar
# #b = B.new
# B.baz

# l = [[1, "one"], [2, "two"], [3, "three"]]

# l.each do |l|
#   a, b = l
#   puts "#{a}\t#{b}"
# end


# DIR = "dir1"
# #DIR = "dir2"
