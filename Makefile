FNAME = evncr
CXX = c++
CFLAGS = -g -O3 -o $(FNAME)

install: main.cc
	$(CXX) $(CFLAGS) main.cc
	mv $(FNAME) /usr/local/bin/
	cp evncr.1 /usr/local/man/man1/$(FNAME).1
	mkdir /usr/local/share/evncr
	cp -r sounds /usr/local/share/evncr/
