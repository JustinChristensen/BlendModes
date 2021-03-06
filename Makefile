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
TESTDIR  := test

SOURCES := $(SRCDIR)/*.cpp
TESTS := $(TESTDIR)/*.cpp

INCLUDES := -I$(SRCDIR)
CXX 	 := g++
CXXFLAGS := $(INCLUDES) -std=c++11 -lUnitTest++

#------------------------------------------------------------------------------
# Targets
#------------------------------------------------------------------------------
all: $(PROGRAM)

$(PROGRAM): $(SOURCES)
	@$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $+
	@$(BINDIR)/$(PROGRAM)

test: $(TESTS)
	@$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $+
	@$(BINDIR)/test

clean: 
	@-rm -rf $(BINDIR)/*

.PHONY: all test clean
