CXX=gcc
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	# The standard (official) Debian Linux way to install 'libpq' circa 2021 is by running:
	#
	#   sudo aptitude install libpq-dev
	#
	# So the following 'CXXFLAGS' definition will work for most Debian based distributions.
	CXXFLAGS=-I/usr/include/postgresql -lpq -std=c99
endif
ifeq ($(UNAME), Darwin)
	# The standard (unofficial) MacOS way to install 'libpq' circa 2021 is by running:
	#
	#   brew install libpq
	#
	# The result is that you have 'include' and 'lib' folder placed in '/usr/local/opt/libpq'.
	# Therefore, we have the following 'CXXFLAGS' definition for MacOS:
	CXXFLAGS=-I/usr/local/opt/libpq/include -L/usr/local/opt/libpq/lib -lpq -std=c99
endif

all: $(patsubst %.c, %.out, $(wildcard *.c))

%.out: %.c Makefile
	$(CXX) $< -o $(@:.out=) $(CXXFLAGS)

clean: $(patsubst %.c, %.clean, $(wildcard *.c))

%.clean:
	rm -f $(@:.clean=)
