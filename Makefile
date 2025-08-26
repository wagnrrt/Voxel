# Executável
TARGET = build/Voxel

# Compilador
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude
LIBS = -lglfw -lGLEW -lGL

# Arquivos fonte
SRC = $(wildcard src/*.cpp)

# Regra principal
all: $(TARGET)

# Compilar e linkar direto
$(TARGET):
	$(CXX) $(CXXFLAGS) -o $@ $(SRC) $(LIBS)

# Limpar
clean:
	rm -rf build/*

# Rodar
run: $(TARGET)
	./$(TARGET)

