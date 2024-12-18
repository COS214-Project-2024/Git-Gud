# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -g -I/usr/include/gtest -I.

# Linker flags
LDFLAGS = -lgtest -lgtest_main -lgmock -lgmock_main -pthread

# Source files common to all builds
COMMON_SRC = Building.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp Transportation.cpp \
             TaxManager.cpp Subject.cpp IndustrialBuilding.cpp Landmark.cpp CommercialBuilding.cpp \
             ResidentialBuilding.cpp Citizen.cpp Education.cpp HealthCare.cpp LawEnforcement.cpp \
             Neutral.cpp Satisfied.cpp Dissatisfied.cpp VerySatisfied.cpp VeryDissatisfied.cpp \
			 BuildingFactory.cpp CommercialBuildingFactory.cpp \
			 BuildingWithCoffeeShopFactory.cpp BuildingWithParkingFactory.cpp PrototypeManager.cpp\
			 IndustrialBuildingFactory.cpp ResidentialBuildingFactory.cpp \
			 BuildingWithCoffeeShop.cpp BuildingWithParking.cpp Decorator.cpp \
			 ResourceManager.cpp Resources.cpp TaxCommercial.cpp TaxFactories.cpp TaxResidents.cpp \
			 Player.cpp LandmarkFactory.cpp


# Object files
COMMON_OBJ = $(COMMON_SRC:.cpp=.o)

# Test source files
TEST_SRC1 = test_Transport.cpp
TEST_SRC2 = test_Resources.cpp
TEST_SRC3 = test_Utilities.cpp
TEST_SRC4 = BuildingTesting.cpp
TEST_SRC5 = CitizenTesting.cpp
TEST_SRC6 = CommercialBuildingsTesting.cpp
TEST_SRC7 = IndustrialBuildingTesting.cpp
TEST_SRC8 = LandmarkBuildingTesting.cpp
TEST_SRC9 = ResidentialBuildingTesting.cpp
TEST_SRC10 = SubjectTest.cpp
TEST_SRC11 = BuildingFactoryTest.cpp
TEST_SRC12 = ExampleTests.cpp
TEST_SRC13 = test_ResourceManager.cpp
TEST_SRC14 = test_PrototypeManager.cpp
TEST_SRC15 = test_Strategy.cpp
TEST_SRC16 = FacadeTest.cpp
TEST_SRC17 = UserInterface.cpp


# Executable names for each test
TARGET1 = test_Transport
TARGET2 = test_Resources
TARGET3 = test_Utilities
TARGET4 = BuildingTesting
TARGET5 = CitizenTesting
TARGET6 = CommercialBuildingsTesting
TARGET7 = IndustrialBuildingTesting
TARGET8 = LandmarkBuildingTesting
TARGET9 = ResidentialBuildingTesting
TARGET10 = SubjectTest
TARGET11 = BuildingFactoryTest
TARGET12 = ExampleTests
TARGET13 = test_ResourceManager
TARGET14 = test_PrototypeManager
TARGET15 = test_Strategy
TARGET16 = test_Facade
TARGET17 = UserInterface


# All test targets
all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET12) $(TARGET13) $(TARGET14) $(TARGET15) $(TARGET16) $(TARGET17)

# Build each test executable
$(TARGET1): $(COMMON_OBJ) $(TEST_SRC1:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC1:.cpp=.o) -o $(TARGET1) $(LDFLAGS)

$(TARGET2): $(COMMON_OBJ) $(TEST_SRC2:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC2:.cpp=.o) -o $(TARGET2) $(LDFLAGS)

$(TARGET3): $(COMMON_OBJ) $(TEST_SRC3:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC3:.cpp=.o) -o $(TARGET3) $(LDFLAGS)

$(TARGET4): $(COMMON_OBJ) $(TEST_SRC4:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC4:.cpp=.o) -o $(TARGET4) $(LDFLAGS)

$(TARGET5): $(COMMON_OBJ) $(TEST_SRC5:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC5:.cpp=.o) -o $(TARGET5) $(LDFLAGS)

$(TARGET6): $(COMMON_OBJ) $(TEST_SRC6:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC6:.cpp=.o) -o $(TARGET6) $(LDFLAGS)

$(TARGET7): $(COMMON_OBJ) $(TEST_SRC7:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC7:.cpp=.o) -o $(TARGET7) $(LDFLAGS)

$(TARGET8): $(COMMON_OBJ) $(TEST_SRC8:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC8:.cpp=.o) -o $(TARGET8) $(LDFLAGS)

$(TARGET9): $(COMMON_OBJ) $(TEST_SRC9:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC9:.cpp=.o) -o $(TARGET9) $(LDFLAGS)

$(TARGET10): $(COMMON_OBJ) $(TEST_SRC10:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC10:.cpp=.o) -o $(TARGET10) $(LDFLAGS)

$(TARGET11): $(COMMON_OBJ) $(TEST_SRC11:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC11:.cpp=.o) -o $(TARGET11) $(LDFLAGS)

$(TARGET12): $(COMMON_OBJ) $(TEST_SRC12:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC12:.cpp=.o) -o $(TARGET12) $(LDFLAGS)

$(TARGET13): $(COMMON_OBJ) $(TEST_SRC13:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC13:.cpp=.o) -o $(TARGET13) $(LDFLAGS)

$(TARGET14): $(COMMON_OBJ) $(TEST_SRC14:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC14:.cpp=.o) -o $(TARGET14) $(LDFLAGS)

$(TARGET15): $(COMMON_OBJ) $(TEST_SRC15:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC15:.cpp=.o) -o $(TARGET15) $(LDFLAGS)

$(TARGET16): $(COMMON_OBJ) $(TEST_SRC16:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC16:.cpp=.o) -o $(TARGET16) $(LDFLAGS)

$(TARGET17): $(COMMON_OBJ) $(TEST_SRC17:.cpp=.o)
	$(CXX) $(COMMON_OBJ) $(TEST_SRC17:.cpp=.o) -o $(TARGET17) $(LDFLAGS)

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run individual tests
transport: $(TARGET1)
	./$(TARGET1)

resources: $(TARGET2)
	./$(TARGET2)

utilities: $(TARGET3)
	./$(TARGET3)

building_test: $(TARGET4)
	./$(TARGET4)

citizen_test: $(TARGET5)
	./$(TARGET5)

commercial_building_test: $(TARGET6)
	./$(TARGET6)

industrial_building_test: $(TARGET7)
	./$(TARGET7)

landmark_building_test: $(TARGET8)
	./$(TARGET8)

residential_building_test: $(TARGET9)
	./$(TARGET9)

subject_test: $(TARGET10)
	./$(TARGET10)

fact_dec_test: $(TARGET11)
	./$(TARGET11)

GE_test: $(TARGET12)
	./$(TARGET12)

resource_manager: $(TARGET13)
	./$(TARGET13)

prototype: $(TARGET14)
	./$(TARGET14)

strategy: $(TARGET15)
	./$(TARGET15)

player: $(TARGET16)
	./$(TARGET16)

ui: $(TARGET17)
	./$(TARGET17)

# Run tests with Valgrind
valgrind: $(TEST_BIN)
	valgrind --leak-check=full --track-origins=yes ./$(TEST_BIN)

# Clean generated files
clean:
	rm -f $(COMMON_OBJ) *.o $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12) $(TARGET13) $(TARGET14)  $(TARGET15) $(TARGET16) $(TARGET17)