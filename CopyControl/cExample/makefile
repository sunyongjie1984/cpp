all : main
main : main.o example.o
	g++ -g -Wall -o main main.o example.o
main.o : main.cpp
	g++ -g -Wall -c main.cpp
example.o : example.cpp example.h
	g++ -g -Wall -c example.cpp
clean :
	rm main.o example.o main
