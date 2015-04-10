[1,2,3].each do |e|
  begin
    Dir.chdir(e.to_s)
  rescue => e
    puts "exception: #{e}"
  end
end
