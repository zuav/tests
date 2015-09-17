def equal_1(a1, a2)
  (a1 == 1) and (a2 == 2)
end

def equal_2(a1, a2)
  v = ['1', '2']
  (a1 == v[0]) and (a2 == v[1])
end

class Foo
  def initialize
    @v = ['1', '2']
  end

  def equal(a1, a2)
    (a1 == @v[0]) and (a2 == @v[1])
  end
end

puts "equal_1(1, 2):     #{equal_1(1, 2)}"
puts "equal_2('1', '2'): #{equal_2('1', '2')}"

foo = Foo.new

puts "foo.equal('1', '2'): #{foo.equal('1', '2')}"
