# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -I/usr/include/gtest -I.

# Linker flags
LDFLAGS = -lgtest -lgtest_main -pthread

# Source files
SRC = DecoratorTest.cpp Building.cpp BuildingWithParking.cpp BuildingWithCoffeeShop.cpp ResidentialBuilding.cpp IndustrialBuilding.cpp CommercialBuilding.cpp Subject.cpp Citizen.cpp Decorator.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp Neutral.cpp Dissatisfied.cpp Satisfied.cpp VeryDissatisfied.cpp VerySatisfied.cpp

# Object files
COMMON_OBJ = $(COMMON_SRC:.cpp=.o)
OBJ1 = $(COMMON_OBJ) $(TEST_SRC1:.cpp=.o)
OBJ2 = $(COMMON_OBJ) $(TEST_SRC2:.cpp=.o)

# Executable name
TARGET = test_decorator

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

valgrind:$(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# Clean
clean:
	rm -f $(OBJ) $(TARGET)
