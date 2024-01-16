CC=g++ -O3 -g -Wall -Wextra -std=c++17

output: main.o Request.o
	$(CC) main.o Request.o -o output.exe

main.o: main.cpp
	$(CC) -c main.cpp

Request.o: Request.cpp Request.hpp
	$(CC) -c Request.cpp

clean:
	rm *.o output