class Bar
  def self.programs(*args)
    if args.size == 0
      @programs ? @programs : []
    else
      @programs = args
    end
  end

  def programs
    self.class.programs
  end
end

class Foo < Bar

  programs 'curl'
  #programs 'ruby', 'rspec'
end

f = Foo.new
p = f.programs
puts p == [] ? "[]" : p.to_s
