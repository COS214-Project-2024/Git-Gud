# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -I/usr/include/gtest -I.

# Linker flags
LDFLAGS = -lgtest -lgtest_main -pthread

# Source files
COMMON_SRC = Building.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp TrafficSimulation.cpp

# Test-specific source files
TEST_SRC1 = test_Transport.cpp
TEST_SRC2 = test_Resources.cpp  

# Object files
COMMON_OBJ = $(COMMON_SRC:.cpp=.o)
OBJ1 = $(COMMON_OBJ) $(TEST_SRC1:.cpp=.o)
OBJ2 = $(COMMON_OBJ) $(TEST_SRC2:.cpp=.o)

# Executable names for each test
TARGET1 = test_Transport
TARGET2 = test_Resources

# Build targets
all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJ1)
	$(CXX) $(OBJ1) -o $(TARGET1) $(LDFLAGS)

$(TARGET2): $(OBJ2)
	$(CXX) $(OBJ2) -o $(TARGET2) $(LDFLAGS)

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
transport: $(TARGET1)
	./$(TARGET1)

resources: $(TARGET2)
	./$(TARGET2)

# Clean
clean:
	rm -f $(COMMON_OBJ) $(OBJ1) $(OBJ2) $(TARGET1) $(TARGET2)

