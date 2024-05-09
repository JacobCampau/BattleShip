battleship: main.o helpers.o board.o player.o enemy.o location.o space.o ship.o
	g++ -o battleship main.o helpers.o board.o player.o enemy.o location.o space.o ship.o -g

main.o: main.cpp helpers.h player.h enemy.h board.h space.h ship.h location.h
	g++ -c main.cpp -g

helpers.o: helpers.cpp helpers.h player.h enemy.h board.h space.h ship.h location.h
	g++ -c helpers.cpp -g

player.o: player.cpp player.h enemy.h board.h space.h ship.h location.h
	g++ -c player.cpp -g

enemy.o: enemy.cpp enemy.h board.h space.h ship.h location.h
	g++ -c enemy.cpp -g

board.o: board.cpp board.h space.h ship.h location.h
	g++ -c board.cpp -g

space.o: space.cpp space.h ship.h location.h
	g++ -c space.cpp -g

ship.o: ship.cpp ship.h location.h
	g++ -c ship.cpp -g

location.o: location.cpp location.h
	g++ -c location.cpp -g

clean:
	rm *.o battleship