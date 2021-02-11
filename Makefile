#---------------------------------------------------
# Makefile for screen saver project :)
#
# make              makes conway screen saver
# make clean        removes all binaries
#---------------------------------------------------

CC = g++
CFLAGS = -Wall
VPATH = algorithms

Conway : main.o conway.o; $(CC) $(CFLAGS) -o Conway main.o conway.o ; rm -f main.o conway.o

main.o : main.cpp conway.h; $(CC) $(CFLAGS) -c main.cpp
    
conway.o : conway.cpp algorithm.h

clean : ; rm -f Conway main.o conway.o
