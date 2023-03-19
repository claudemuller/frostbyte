CC=g++
FLAGS=-Wall -std=c++17 -D_THREAD_SAFE
INCS=-I/opt/homebrew/include -I./libs/ -I./libs/lua/
LIBS=-L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua
SRC=./src/*.cpp
BIN=gameengine

all: clean build run

build:
	$(CC) $(SRC) $(FLAGS) $(INCS) $(LIBS) -o $(BIN)

debug:
	$(CC) -g $(SRC) $(FLAGS) $(INCS) $(LIBS) -o debug

run:
	./$(BIN)

clean:
	rm -rf $(BIN) debug
