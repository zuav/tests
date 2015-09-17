require 'rugged'


creds = Rugged::Credentials::SshKey.new(username: 'git',
                                        publickey: File.expand_path("~/.ssh/id_rsa.pub"),
                                        privatekey: File.expand_path("~/.ssh/id_rsa"))
#repo = Rugged::Repository.clone_at  'git@git.crystax.net:android/crew.git', '/tmp/crew', credentials: creds
repo = Rugged::Repository.init_at '/tmp/crew', credentials: creds

puts repo.remotes['origin'].url


repo.close
