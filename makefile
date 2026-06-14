# Nombre del ejecutable
TARGET = main

# Buscar todos los .cpp excepto los que inician con test
SOURCES := $(filter-out test%.cpp, $(wildcard *.cpp))

# Regla principal
$(TARGET):
	$(CXX) $(SOURCES) -o $(TARGET)

# Limpieza
clean:
	$(RM) $(TARGET)
