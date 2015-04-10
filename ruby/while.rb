n = 1
n += 1 while File.exists?("/tmp/file.txt.#{n}")
`touch /tmp/file.txt.#{n}`
