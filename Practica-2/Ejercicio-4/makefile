INC = include
SRC = src
OBJ = obj
LIB = lib
BIN = bin

CXX = g++

all : $(BIN)/moda
		  echo "Uso => ./bin/moda TAM | MAX_N"

$(OBJ)/moda.o: $(SRC)/moda.cpp
	$(CXX) -c $(SRC)/moda.cpp -o $(OBJ)/moda.o

$(BIN)/moda: $(OBJ)/moda.o
	$(CXX) -o $(BIN)/moda $(OBJ)/moda.o

clean:
		echo "limpiando..."
		rm $(OBJ)/*

mrproper: clean
		rm $(BIN)/*
