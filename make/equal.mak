# -*- Makefile -*-

value1 = one
value2 = two

export_flags  = var1=$(value1)
export_flags += var2=$(value2)

export_str = $(export_flags)

all:
	$(export_flags) ./equal.sh
