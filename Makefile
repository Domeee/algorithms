CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: algorithms

algorithms: main.o bfs.o
	$(CXX) $(CXXFLAGS) -o algorithms main.o bfs.o

main.o: main.cpp bfs.h
	$(CXX) $(CXXFLAGS) -c main.cpp

bfs.o: bfs.cpp bfs.h
	$(CXX) $(CXXFLAGS) -c bfs.cpp

clean:
	rm -f *.o algorithms
