CC=g++ -O3 -g -Wall -Wextra -std=c++17

output: main.o StatisticalRequest.o Request.o Statistics.o
	$(CC) main.o StatisticalRequest.o Request.o Statistics.o -o output.exe

main.o: main.cpp
	$(CC) -c main.cpp

Request.o: Request.cpp Request.hpp
	$(CC) -c Request.cpp

StatisticalRequest.o: StatisticalRequest.cpp StatisticalRequest.hpp
	$(CC) -c StatisticalRequest.cpp

Statistics.o: Statistics.cpp Statistics.hpp
	$(CC) -c Statistics.cpp
	
test.o: test.cpp
	$(CC) -c test.cpp

test: test.o Request.o StatisticalRequest.o Statistics.o testUtils.cpp
	$(CC) test.o Request.o StatisticalRequest.o Statistics.o -o test.exe

run: output
	./output.exe

run-test: test
	./test.exe

clean:
	rm *.o