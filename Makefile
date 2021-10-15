# Makefile                                                                                                                                                                        

CXX_FLAG = --std=c++11 -ggdb



all: project1.o Hash.o Hashbucket.o
	g++ $(CXX_FLAG) -o project1 project1.o Hash.o Hashbucket.o

project1.o: project1.cpp
	g++ -c $(CXX_FLAG) project1.cpp

Hash: Hash.o Hashbucket.o
	g++ $(CXX_FLAG) -o Hash Hash.o Hashbucket.o

Hashbucket: Hashbucket.o
	g++ $(CXX_FLAG) -o Hashbucket Hashbucket.o

Hash.o: Hash.cpp
	g++ -c $(CXX_FLAG) Hash.cpp Hash.h

Hashbucket.o: Hashbucket.cpp
	g++ -c $(CXX_FLAG) Hashbucket.cpp Hashbucket.h

clean:
	rm -f project1 *.o
