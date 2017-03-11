#------------------------------------------------------------------------------
#Katerina Chinnappan - kachinna
# Makefile for CMPS 109 Programming Project
#
#       make                   makes Main
#------------------------------------------------------------------------------
GPP = g++ -std=c++11
GPPFLAGS = -O3 -ansi -Wall

all: SRI

SRI: SRI/Main.o
	$(GPP) $(GPPFLAGS) SRI/Main.o  -o Main

clean:
	rm -f *.exe
	rm -f SRI/*.o
	rm -f SRI

%.o: %.cc
	g++ -c $< -o $@
	
