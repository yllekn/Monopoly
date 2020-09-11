CXX 		= g++
CXXFLAGS 	= -Wall -std=c++11

main: main.o game.o
	$(CXX) $(CXXFLAGS) -o main main.o game.o

main.o: main.cpp game.hpp player.hpp board.hpp constants.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

game.o: player.hpp board.hpp constants.hpp

clean: 
	$(RM) main *.o