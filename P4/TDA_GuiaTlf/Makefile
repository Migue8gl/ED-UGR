SRC = ./src
INC = ./include
OBJS = ./obj
BIN = ./bin
DOC = ./doc
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/testguia

$(BIN)/testguia: $(OBJS)/testguia.o
	$(CXX) -o $(BIN)/testguia $(OBJS)/testguia.o

$(OBJS)/testguia.o: $(SRC)/testguia.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testguia.cpp -o $(OBJS)/testguia.o

clean:
	rm -f -r $(OBJS)/* $(DOC)/* $(BIN)/*

dox:
	doxygen Doxy-file

