class Foo

  attr_accessor :rm_binary, :rm_source

  def initialize(rm_binary: true, rm_source: false)
    @rm_binary = rm_binary
    @rm_source = rm_source
  end
end

foo1 = Foo.new(rm_binary: false, rm_source: true)
puts "rm_binary: #{foo1.rm_binary}"
puts "rm_source: #{foo1.rm_source}"

foo2 = Foo.new
puts "rm_binary: #{foo2.rm_binary}"
puts "rm_source: #{foo2.rm_source}"
