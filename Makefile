FNAME = evncr

install:
	cabal install --haddock-all --overwrite-policy=always evncr
	cp evncr.1 /usr/local/man/man1/$(FNAME).1
	ls /usr/local/share/$(FNAME) || mkdir /usr/local/share/$(FNAME)
	cp -r sound /usr/local/share/$(FNAME)/

uninstall:
	rm -r /usr/local/share/$(FNAME)
	rm /use/local/man/man1/$(FNAME).1
