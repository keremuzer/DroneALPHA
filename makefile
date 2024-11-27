# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -g

# Source and Object Files
SRC = main.cpp RoutePlanner.cpp Map.cpp Queue.cpp Stack.cpp
OBJ = $(SRC:.cpp=.o)

# Output Executable
TARGET = DroneALPHA

# Default Target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Compile Individual Source Files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Build Artifacts
clean:
	rm -f $(OBJ) $(TARGET)
