CXX=gcc
CXXFLAGS=-I/usr/include/postgresql -lpq -std=c99

all: $(patsubst %.c, %.out, $(wildcard *.c))

%.out: %.c Makefile
	$(CXX) $< -o $(@:.out=) $(CXXFLAGS)

clean: $(patsubst %.c, %.clean, $(wildcard *.c))

%.clean:
	rm -f $(@:.clean=)
