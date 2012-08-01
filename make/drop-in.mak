# -*- Makefile -*-

src  = f1.txt.in f2.txt.in f3.txt.in
dst1 = $(src:.in=)
dst2 = $(src:.txt.in=.script)

all:
	@echo $(src)
	@echo $(dst1)
	@echo $(dst2)
