CC = g++
CFLAGS = -Wall

main: main.o database.o Parser.o
	$(CC) $(CFLAGS) -o main main.o database.o Parser.o

main.o: main.cpp database.h Solver.h
	$(CC) $(CFLAGS) -c main.cpp

database.o: database.cpp database.h Parser.h
	$(CC) $(CFLAGS) -c database.cpp

Parser.o: Parser.cpp Parser.h
	$(CC) $(CFLAGS) -c Parser.cpp

clean:
	rm -f *.o main
