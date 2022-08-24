SRC = ./src
INC = ./include
OBJS = ./obj
BIN = ./bin
DOC = ./doc
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usopilas_max

$(BIN)/usopilas_max: $(OBJS)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJS)/usopilas_max.o

$(OBJS)/usopilas_max.o: $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJS)/usopilas_max.o

clean:
	rm -f -r $(OBJS)/* $(DOC)/* $(BIN)/*

dox:
	doxygen Doxy-file

