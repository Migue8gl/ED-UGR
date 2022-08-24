SRC = ./src
INC = ./include
OBJS = ./obj
BIN = ./bin
DOC = ./doc
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/testdiccionario

$(BIN)/testdiccionario: $(OBJS)/testdiccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJS)/testdiccionario.o

$(OBJS)/testdiccionario.o: $(SRC)/testdiccionario.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testdiccionario.cpp -o $(OBJS)/testdiccionario.o

clean:
	rm -f -r $(OBJS)/* $(DOC)/* $(BIN)/*

dox:
	doxygen Doxy-file

