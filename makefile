CXXFLAGS = -std=c++17 -Wall -g
GTEST_LIB = -lgtest -lgtest_main -pthread

# Source files and tests (only SubjectTest.cpp)
SRC = TaxManager.cpp Subject.cpp ResidentialBuilding.cpp Landmark.cpp Citizen.cpp Building.cpp Education.cpp HealthCare.cpp LawEnforcement.cpp ResourceManager.cpp test_Resources.cpp test_ResourceManager.cpp test_Utility.cpp
TEST_SRC = SubjectTest.cpp

# Output for tests
TEST_BIN = test_suite

# Build and link all tests
all: $(TEST_BIN)

$(TEST_BIN): $(SRC) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST_SRC) -o $(TEST_BIN) $(GTEST_LIB)

# Run tests
test: $(TEST_BIN)
	./$(TEST_BIN)

# Clean up generated files
clean:
	rm -f $(TEST_BIN) *.o