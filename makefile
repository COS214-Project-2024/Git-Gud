# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -I/usr/include/gtest -I.

# Linker flags
LDFLAGS = -lgtest -lgtest_main -pthread

# Source files
SRC = test_Transport.cpp Building.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp TrafficSimulation.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
TARGET = test_Transport

# Build target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(TARGET)
	./$(TARGET)

# Clean
clean:
	rm -f $(OBJ) $(TARGET)
