CFLAGS = -Wall -Wextra -std=c99 -g
CPPFLAGS = -I.
LDFLAGS =


all: hello po/ru/hello.mo


hello: hello.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

po/ru/hello.mo: po/ru/hello.po
	msgfmt --output-file=$@ $<

po/ru/hello.po: po/hello.pot
	msgmerge --update $@ $<

po/hello.pot: hello.c
	xgettext -k_ -j -lC -c -s -o po/hello.pot hello.c

clean:
	@rm -f hello po/ru/*.mo *~

.PHONY: clean
