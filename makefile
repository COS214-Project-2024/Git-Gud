# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
GTEST_LIB = -lgtest -lgtest_main -pthread

# Source files
COMMON_SRC = Building.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp Citizen.cpp \
              Subject.cpp Player.cpp TaxManager.cpp TaxResidents.cpp TaxFactories.cpp \
              TaxCommercial.cpp IndustrialBuilding.cpp ResidentialBuilding.cpp CommercialBuilding.cpp \
              Neutral.cpp Satisfied.cpp Dissatisfied.cpp VerySatisfied.cpp VeryDissatisfied.cpp

# Test-specific source files
TEST_SRC3 = test_Strategy.cpp  

# Object files
COMMON_OBJ = $(COMMON_SRC:.cpp=.o)
OBJ3 = $(COMMON_OBJ) $(TEST_SRC3:.cpp=.o)

# Executable names for each test
TARGET3 = test_Strategy

# Build targets
all: $(TARGET3)

# Link and create the test executable
$(TARGET3): $(OBJ3)
	$(CXX) $(OBJ3) -o $(TARGET3) $(GTEST_LIB)  # Make sure to link against Google Test libraries

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(TARGET3)
	./$(TARGET3)

# Clean
clean:
	rm -f $(COMMON_OBJ) $(OBJ3) $(TARGET3)
