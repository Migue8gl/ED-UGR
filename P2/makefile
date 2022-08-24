#!/bin/bash
OBJS	= ./obj
EXE	= programa_imagen
CC	= g++
INC	= ./include
SRC	= ./src
BIN	= ./bin
DOC	= ./doc

all: $(BIN)/$(EXE)
 
$(BIN)/$(EXE): $(OBJS)/main.o $(OBJS)/Imagen.o $(OBJS)/imagenES.o
	$(CC) -o $(BIN)/$(EXE) $(OBJS)/main.o $(OBJS)/Imagen.o $(OBJS)/imagenES.o

$(OBJS)/main.o: $(SRC)/main.cpp
	$(CC) -c -I$(INC) $(SRC)/main.cpp -o $(OBJS)/main.o

$(OBJS)/Imagen.o: $(SRC)/Imagen.cpp
	$(CC) -c -I$(INC) $(SRC)/Imagen.cpp -o $(OBJS)/Imagen.o

$(OBJS)/imagenES.o: $(SRC)/imagenES.cpp
	$(CC) -c -I$(INC) $(SRC)/imagenES.cpp -o $(OBJS)/imagenES.o

clean:
	rm -f -r $(OBJS)/* $(DOC)/* $(BIN)/*

dox:
	doxygen Doxy-file

