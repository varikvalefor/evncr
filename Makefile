FNAME = evncr
CXX = c++
CFLAGS = -g -O3 -o $(FNAME)

install: main.cc
	$(CXX) $(CFLAGS) main.cc
	mv $(FNAME) /usr/local/bin/
	chmod 711 /usr/local/bin/$(FNAME)
	cp evncr.1 /usr/local/man/man1/$(FNAME).1
	ls /usr/local/share/$(FNAME) || mkdir /usr/local/share/$(FNAME)
	cp -r sound /usr/local/share/$(FNAME)/
