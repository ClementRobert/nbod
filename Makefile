#all:
#CC = g++
CFLAGS = -g -Wall
TARGET = program

$(TARGET) : sources/* main_cluster.cpp
	g++ $(CFLAGS) -I headers/ sources/*.cpp main_cluster.cpp -o $(TARGET) 
#clean:
#	rm *o
