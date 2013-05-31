# Makefile
#
# Justin Christensen
# Fri May 31 09:29:16 2013
#

#------------------------------------------------------------------------------
# Variables
#------------------------------------------------------------------------------
PROGRAM = main

SRCDIR   := src
BINDIR   := bin
LIBDIR   := lib
TESTDIR  := test

SOURCES := $(SRCDIR)/*.cpp
TESTS := $(TESTDIR)/*.cpp

INCLUDES = -I$(LIBDIR)/UnitTest++ -I$(SRCDIR)

CXX 	 := g++
CXXFLAGS := $(INCLUDES) -std=c++11 

#------------------------------------------------------------------------------
# Targets
#------------------------------------------------------------------------------
all: $(PROGRAM)

$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $+

test: $(TESTS)
	g++ $(CXXFLAGS) -o $(BINDIR)/$@ $+
	@$(BINDIR)/test

clean: 
	@-rm -rf $(PROGRAM)

.PHONY: all test clean
