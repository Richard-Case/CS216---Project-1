all: Project1

Project1: main.o Analyze.o Autocomplete.o
	g++ -o Project1 main.o Analyze.o Autocomplete.o

main.o: main.cpp
	g++ -c main.cpp

Analyze.o: Analyze.cpp Analyze.h
	g++ -c Analyze.cpp

imdb.o: imdb.cpp imdb.h Strings.h
	g++ -c imdb.cpp