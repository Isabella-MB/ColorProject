# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -O2

# SFML library and include paths
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
SFML_INCS = -I/usr/include/SFML

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Output file
TARGET = $(BIN_DIR)/my_program

# Source files
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY:	all clean

all: $(TARGET)

# Build the program
$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CXX) $(SFML_INCS) $^ $(SFML_LIBS) -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Compile the source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_INCS) -c $< -o $@
	$(CXX) $(CXXFLAGS) $(SFML_INCS) -MM $< > $(OBJ_DIR)/$*.d

# Clean the build directory
clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
