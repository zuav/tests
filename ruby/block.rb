class Foo

  def fun(s1, s2)
    @s1 = s1
    @s2 = s2
    yield
  end

  def set_s3(v)
    @s3 = v
  end

  def set_s4(v)
    @s4 = v
  end

  def to_s
    "s1 = #{@s1}; s2 = #{@s2}; s3 = #{@s3}; s4 = #{@s4}"
  end
end


f = Foo.new
puts f

f.fun(1, 2) { puts "block" }
puts f

f.fun 1, 2 do
  set_s3 3
  set_s4 4
end
