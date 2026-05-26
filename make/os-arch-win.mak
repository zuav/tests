# -*- Makefile -*-

#os_arch = $(PROCESSOR_ARCHITECTURE)
os_arch = $(shell ./t.cmd)

ifeq ($(PROCESSOR_ARCHITECTURE), AMD64)
  os_arch = amd64
else ifeq ($(PROCESSOR_ARCHITEW6432), AMD64)
  os_arch = amd64
else
  os_arch = x686
endif

#os_arch = $(strip $(shell echo $$PROCESSOR_ARCHITECTURE | awk '{print tolower(S1) }'))

all:
	echo $(os_arch)
