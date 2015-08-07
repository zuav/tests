# -*- Makefile -*-

# Define HAVE_CLOCK_GETTIME if you have foo

#undefine HAVE_CLOCK_GETTIME

ifdef HAVE_CLOCK_GETTIME
	OK = bla
else
	OK = ok
endif

all:
	@echo $(OK)
