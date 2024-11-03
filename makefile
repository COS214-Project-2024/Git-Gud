CXXFLAGS = -std=c++17 -Wall -g
GTEST_LIB = -lgtest -lgtest_main -pthread

# Source files and tests (only SubjectTest.cpp)
SRC = TaxManager.cpp Subject.cpp ResidentialBuilding.cpp Landmark.cpp Citizen.cpp Building.cpp Education.cpp HealthCare.cpp LawEnforcement.cpp ResourceManager.cpp test_Resources.cpp test_ResourceManager.cpp test_Utility.cpp
TEST_SRC = SubjectTest.cpp

# Output for tests
TEST_BIN = test_suite

<<<<<<< Updated upstream
# Build and link all tests
all: $(TEST_BIN)

$(TEST_BIN): $(SRC) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST_SRC) -o $(TEST_BIN) $(GTEST_LIB)
=======
# Source files
COMMON_SRC = Building.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp TrafficSimulation.cpp Citizen.cpp Subject.cpp Player.cpp TaxManager.cpp TaxResidents.cpp TaxFactories.cpp TaxCommercial.cpp IndustrialBuilding.cpp ResidentialBuilding.cpp CommercialBuilding.cpp Neutral.cpp Satisfied.cpp Dissatisfied.cpp VerySatisfied.cpp VeryDissatisfied.cpp

# Test-specific source files
TEST_SRC1 = test_Transport.cpp
TEST_SRC2 = test_Resources.cpp  
TEST_SRC3 = test_Strategy.cpp  

# Object files
COMMON_OBJ = $(COMMON_SRC:.cpp=.o)
OBJ1 = $(COMMON_OBJ) $(TEST_SRC1:.cpp=.o)
OBJ2 = $(COMMON_OBJ) $(TEST_SRC2:.cpp=.o)
OBJ3 = $(COMMON_OBJ) $(TEST_SRC3:.cpp=.o)

# Executable names for each test
TARGET1 = test_Transport
TARGET2 = test_Resources
TARGET3 = test_Strategy

# Build targets
all: $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1): $(OBJ1)
	$(CXX) $(OBJ1) -o $(TARGET1) $(LDFLAGS)

$(TARGET2): $(OBJ2)
	$(CXX) $(OBJ2) -o $(TARGET2) $(LDFLAGS)

$(TARGET3): $(OBJ3)
	$(CXX) $(OBJ3) -o $(TARGET3) $(LDFLAGS)

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
>>>>>>> Stashed changes

# Run tests
test: $(TEST_BIN)
	./$(TEST_BIN)

<<<<<<< Updated upstream
# Clean up generated files
clean:
	rm -f $(TEST_BIN) *.o
=======
resources: $(TARGET2)
	./$(TARGET2)

strategy: $(TARGET3)
	./$(TARGET3)

# Clean
clean:
	rm -f $(COMMON_OBJ) $(OBJ1) $(OBJ2) $(TARGET1) $(TARGET2) $(OBJ3) $(TARGET3)

>>>>>>> Stashed changes
