os_name = $(strip $(shell uname))

$(error "Unsupported OS: $(os_name)")
