require 'fileutils'

files = []
FileUtils.cd('/tmp') { files = Dir.glob('*') }

puts files
