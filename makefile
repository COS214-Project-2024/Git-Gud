# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -I/usr/include/gtest -I.

# Linker flags
LDFLAGS = -lgtest -lgtest_main -pthread

# Source files
SRC = DecoratorTest.cpp Building.cpp BuildingWithParking.cpp BuildingWithCoffeeShop.cpp ResidentialBuilding.cpp IndustrialBuilding.cpp CommercialBuilding.cpp Subject.cpp Citizen.cpp Decorator.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp Neutral.cpp Dissatisfied.cpp Satisfied.cpp VeryDissatisfied.cpp VerySatisfied.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
TARGET = test_decorator

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