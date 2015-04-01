class Foo
  attr_reader :architectures
  def initialize
    @architectures = []
  end
  def architectures=(l)
    @architectures = l
    if ind = l.index("arm")
      @architectures.insert(ind, "armeabi-v7a")
    end
  end
end

a = Foo.new

a.architectures = ["x86", "mips"]
puts a.architectures

a.architectures = ["arm", "x86", "mips"]
puts a.architectures
