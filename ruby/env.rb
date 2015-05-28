s1 = `echo "foo = $foo"`
puts s1

ENV["foo"] = "foo"
s2 = `echo "foo = $foo"`
puts s2

ENV.delete "foo"
s3 = `echo "foo = $foo"`
puts s3
