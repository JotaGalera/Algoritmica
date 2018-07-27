INC = include
SRC = src
OBJ = obj
LIB = lib
BIN = bin

CXX = g++

all : $(BIN)/zapatos
		  echo "Uso => ./bin/zapatos TAM | MAX_N"

$(OBJ)/zapatos.o: $(SRC)/zapatos.cpp
	$(CXX) -c $(SRC)/zapatos.cpp -o $(OBJ)/zapatos.o

$(BIN)/zapatos: $(OBJ)/zapatos.o
	$(CXX) -o $(BIN)/zapatos $(OBJ)/zapatos.o

clean:
		echo "limpiando..."
		rm $(OBJ)/*

mrproper: clean
		rm $(BIN)/*
