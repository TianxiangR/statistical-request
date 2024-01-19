CC=g++ -O3 -g -Wall -Wextra -std=c++17

Request.o: Request.cpp Request.hpp
    $(CC) -c Request.cpp

StatisticalRequest.o: StatisticalRequest.cpp StatisticalRequest.hpp
    $(CC) -c StatisticalRequest.cpp

Statistics.o: Statistics.cpp Statistics.hpp
    $(CC) -c Statistics.cpp
	
test: test.cpp Request.o StatisticalRequest.o Statistics.o testUtils.cpp
    $(CC) test.cpp Request.o StatisticalRequest.o Statistics.o -o test.exe

run-test: test
    ./test.exe

clean:
    rm *.o