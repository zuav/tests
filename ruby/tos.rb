class A
  def initialize(num)
    @num = num
  end

  def to_s
    @num.to_s
  end
end

puts ([1, 2].map {|n| A.new(n) }).join(',')
