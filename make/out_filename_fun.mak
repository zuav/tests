# -*- Makefile -*-

.PHONY: all

fun1 = -o $(1)
fun2 = /Fo$(1)


all:
	@echo fun1 result: $(call fun1,file).
	@echo fun2 result: $(call fun2,file).
