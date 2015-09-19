#run 'make' in command line to run compilation according to rules described in this file
MAIN = main_cluster.cpp
CFLAGS = -g -Wall -std=c++11 -Wextra -ansi -pedantic -O2 -s
TARGET = program

$(TARGET) : sources/* main_cluster.cpp
	g++ $(CFLAGS) -I headers sources/*.cpp $(MAIN) -o $(TARGET) 
#clean:
#	rm *o
