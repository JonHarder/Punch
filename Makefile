all: Game

Game: *.o
	g++ -Wall -g -o Game *.o -lsfml-system -lsfml-window -lsfml-graphics -std=c++11

*.o: *.cpp
	g++ -c *.cpp

clean:
	rm *.o Game
