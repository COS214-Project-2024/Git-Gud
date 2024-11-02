# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -I/usr/include/gtest -I.

# Linker flags
LDFLAGS = -lgtest -lgtest_main -pthread

# Source files
#SRC = DecoratorTest.cpp Building.cpp BuildingWithParking.cpp BuildingWithCoffeeShop.cpp ResidentialBuilding.cpp IndustrialBuilding.cpp CommercialBuilding.cpp Subject.cpp Citizen.cpp Decorator.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp Neutral.cpp Dissatisfied.cpp Satisfied.cpp VeryDissatisfied.cpp VerySatisfied.cpp

SRC = BuildingFactoryTest.cpp BuildingFactory.cpp CommercialBuildingFactory.cpp BuildingWithCoffeeShopFactory.cpp BuildingWithParkingFactory.cpp IndustrialBuildingFactory.cpp ResidentialBuildingFactory.cpp Building.cpp BuildingWithCoffeeShop.cpp BuildingWithParking.cpp IndustrialBuilding.cpp CommercialBuilding.cpp ResidentialBuilding.cpp Subject.cpp Citizen.cpp Decorator.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp Neutral.cpp Dissatisfied.cpp Satisfied.cpp VeryDissatisfied.cpp VerySatisfied.cpp ResourceManager.cpp Resources.cpp

# Executable name
TARGET = test_fact

# Build targets

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

OBJ = $(SRC:.cpp=.o)

# Build targets

# Link the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Run tests
test: $(TARGET)
	./$(TARGET)

valgrind:$(TARGET)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(TARGET)

# Clean
clean:
	rm -f $(OBJ) $(TARGET)
