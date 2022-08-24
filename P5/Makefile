SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/rutas_aereas

$(BIN)/rutas_aereas: $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/almacen_rutas.o $(OBJ)/Ruta.o $(OBJ)/Punto.o
	$(CXX) -o $(BIN)/rutas_aereas $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/almacen_rutas.o $(OBJ)/Ruta.o $(OBJ)/Punto.o

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/rutas_aereas.cpp -o $(OBJ)/rutas_aereas.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/Punto.o: $(SRC)/Punto.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Punto.cpp -o $(OBJ)/Punto.o

$(OBJ)/Ruta.o: $(SRC)/Ruta.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Ruta.cpp -o $(OBJ)/Ruta.o

$(OBJ)/almacen_rutas.o: $(SRC)/almacen_rutas.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/almacen_rutas.cpp -o $(OBJ)/almacen_rutas.o
		
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
