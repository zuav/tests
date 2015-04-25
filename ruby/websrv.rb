require 'webrick'

PORT = 9999

download_base = "http://localhost:#{PORT}"
www_dir =  'www'
docroot_dir = File.join(www_dir, 'docroot')
log_dir = File.join(www_dir, 'log')
base_dir = 'crew'
ndk_dir = 'ndk'
data_dir = 'data'

FileUtils.mkdir(log_dir) unless Dir.exist?(log_dir)

# server = WEBrick::HTTPServer.new :Port => PORT,
#                                  :DocumentRoot => docroot_dir,
#                                  :Logger => WEBrick::Log.new(File.join(www_dir, 'log', 'webrick.log')),
#                                  :AccessLog => [[File.open(File.join(www_dir, 'log', 'access.log'),'w'),
#                                                  WEBrick::AccessLog::COMBINED_LOG_FORMAT]]
server = WEBrick::HTTPServer.new :Port => PORT,
                                 :DocumentRoot => docroot_dir

server.start
