# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I /usr/local/include
LDFLAGS = -L /usr/local/lib -lgtest -lgtest_main -lpthread

# Source files
SOURCES = Resources.cpp ResourceManager.cpp test_Resources.cpp test_ResourceManager.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = runTests

# Rules
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the tests
test: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean up build files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)