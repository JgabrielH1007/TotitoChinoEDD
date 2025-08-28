# Compilador y banderas
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Archivos fuente y objeto
SRC = main.cpp AdministradorDeJuego.cpp AdministradorDeTablero.cpp Jugador.cpp ListaJugadores.cpp ListaLineas.cpp PilaPowerUps.cpp 
OBJ = $(SRC:.cpp=.o)

# Nombre del ejecutable
TARGET = practica1

# Regla por defecto
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Cómo compilar cada archivo .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ) $(TARGET)
