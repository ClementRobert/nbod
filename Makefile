#run 'make' in command line to run compilation according to rules described in this file
MAIN = main.cpp
CFLAGS = -g -Wall -std=c++11 -Wextra -ansi -pedantic -O2 -s
GRAPHFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = program


$(TARGET) : sources/* $(MAIN)
	g++ $(CFLAGS) -I headers sources/*.cpp $(MAIN) -o $(TARGET) $(GRAPHFLAGS) 
#clean:
#	rm *o
