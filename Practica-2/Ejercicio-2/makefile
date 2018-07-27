INC = include
SRC = src
OBJ = obj
LIB = lib
BIN = bin

CXX = g++

all : $(BIN)/max_min_matriz
		  echo "Uso => ./bin/max_min_matriz TAM"

$(OBJ)/max_min_matriz.o: $(SRC)/max_min_matriz.cpp
	$(CXX) -c $(SRC)/max_min_matriz.cpp -o $(OBJ)/max_min_matriz.o

$(BIN)/max_min_matriz: $(OBJ)/max_min_matriz.o
	$(CXX) -o $(BIN)/max_min_matriz $(OBJ)/max_min_matriz.o

clean:
		echo "limpiando..."
		rm $(OBJ)/*

mrproper: clean
		rm $(BIN)/*
