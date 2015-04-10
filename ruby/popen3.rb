require 'open3'

outstr = ""
Open3.popen3("ls -la /tmp" ) do |_, out, err, t|
  ot = Thread.start do
    while c = out.getc
      outstr += "#{c}"
    end
  end

  errstr = ""
  et = Thread.start do
    while c = err.getc
      errstr += "#{c}"
    end
  end

  ot.join
  et.join

  raise "error during execution: #{errstr}" unless t.value.success?
end

raise "\$? not set" unless $?

puts outstr
