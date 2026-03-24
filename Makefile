# Compilateur et flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Nom de l'exécutable
TARGET = jeu

# Fichiers sources et objets
SOURCES = main.cpp Animal.cpp Attaque.cpp Loup.cpp Pierre.cpp Lion.cpp Ours.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compilation des fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Nettoyage des fichiers compilés
clean:
	rm -f $(OBJECTS) $(TARGET)

# Exécution du programme
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
