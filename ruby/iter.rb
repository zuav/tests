class Foo
  def initialize
    @h = {one: 1, two: 2, three: 3}
  end

  def each(&block)
    @h.each_value(&block)
  end
end

foo = Foo.new
foo.each { |e| puts e }
