CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = src
OBJ_DIR = obj
EXEC = algorithms

# Automatically find all cpp files in the SRC_DIR
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Replace .cpp with .o and prefix with OBJ_DIR
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Default target
all: $(EXEC)

# Link all object files into the final executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each cpp file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the object files directory if it doesn't exist
$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

# Clean target to remove build artifacts
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Mark targets as phony
.PHONY: all clean
