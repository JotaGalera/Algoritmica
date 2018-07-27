INC = include
SRC = src
OBJ = obj
LIB = lib
BIN = bin

CXX = g++

all : $(BIN)/max_min
			echo "Uso => ./bin/max_min TAM"

$(OBJ)/max_min.o: $(SRC)/max_min.cpp
	$(CXX) -c $(SRC)/max_min.cpp -o $(OBJ)/max_min.o

$(BIN)/max_min: $(OBJ)/max_min.o
	$(CXX) -o $(BIN)/max_min $(OBJ)/max_min.o

clean:
		echo "limpiando..."
		rm $(OBJ)/*

mrproper: clean
		rm $(BIN)/*
