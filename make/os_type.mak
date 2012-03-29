# -*- Makefile -*-

ifdef COMSPEC
  os_type = Windows
else ifdef ComSpec
  os_type = Windows
else ifdef comspec
  os_type = Windows
else
  os_type = Unix
endif


all:
	@echo OS type is: $(os_type).
