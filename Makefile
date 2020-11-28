FNAME = evncr
HASK = ghc
FLAGS = -O3
FNAME = evncr

install: evncr.hs
	$(HASK) $(FLAGS) evncr.hs
	mv $(FNAME) /usr/local/bin/
	chmod 711 /usr/local/bin/$(FNAME)
	cp evncr.1 /usr/local/man/man1/$(FNAME).1
	ls /usr/local/share/$(FNAME) || mkdir /usr/local/share/$(FNAME)
	cp -r sound /usr/local/share/$(FNAME)/
	rm *.hi *.o
uninstall:
	rm /usr/local/bin/$(FNAME)
	rm -r /usr/local/share/$(FNAME)
	rm /use/local/man/man1/$(FNAME).1
