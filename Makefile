CXX = c++
CFLAGS = -g -o evncr

install: main.cc
	$(CXX) $(CFLAGS) main.cc
	mv evncr /usr/local/bin/
	cp evncr.1 /usr/local/man/man1
