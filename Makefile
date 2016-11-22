all: compile run clean

compile: main.cpp parser.cpp parser.h utils.cpp utils.h hotel.cpp hotel.h floor.cpp floor.h room.cpp room.h person.cpp person.h info.txt commands.txt
	@g++ -std=c++11 main.cpp parser.cpp utils.cpp hotel.cpp floor.cpp room.cpp person.cpp -o main

run: main
	@./main

clean: main
	@rm main
