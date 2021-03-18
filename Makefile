FNAME = evncr
HASK = ghc
FLAGS = -O3

install: evncr.hs
	$(HASK) $(FLAGS) evncr.hs
	mv $(FNAME) /usr/local/sbin/
	chmod 711 /usr/local/sbin/$(FNAME)
	cp evncr.1 /usr/local/man/man1/$(FNAME).1
	ls /usr/local/share/$(FNAME) || mkdir /usr/local/share/$(FNAME)
	cp -r sound /usr/local/share/$(FNAME)/
	rm *.hi *.o
uninstall:
	rm /usr/local/bin/$(FNAME)
	rm /usr/local/sbin/$(FNAME)
	rm -r /usr/local/share/$(FNAME)
	rm /use/local/man/man1/$(FNAME).1
