class Foo
  def bar(arg=nil)
    puts "arg = #{arg}"
  end
end

f = Foo.new
f.bar
f.bar(:baz)
