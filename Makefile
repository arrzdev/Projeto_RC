# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
USER_DIR = src/user
SERVER_DIR = src/server
COMMON_DIR = src/common

# Find all cpp files in the user and server directories
USER_SOURCES = $(wildcard $(USER_DIR)/*.cpp)
SERVER_SOURCES = $(wildcard $(SERVER_DIR)/*.cpp)
COMMON_SOURCES = $(wildcard $(COMMON_DIR)/*.cpp)

# Executable names
USER_EXEC = ./user
SERVER_EXEC = ./server

# Default target is to build the user and server executables but before clean
all: clean $(USER_EXEC) $(SERVER_EXEC)

# Rules for building user and server executables
$(USER_EXEC):
	$(CXX) $(CXXFLAGS) $(USER_SOURCES) $(COMMON_SOURCES) -o $(USER_EXEC)

$(SERVER_EXEC):
	$(CXX) $(CXXFLAGS) $(SERVER_SOURCES) $(COMMON_SOURCES) -o $(SERVER_EXEC)

# Debugging
debug:
	@echo "User Sources: $(USER_SOURCES)"
	@echo "Server Sources: $(SERVER_SOURCES)"
	@echo "Common Sources: $(COMMON_SOURCES)"

# Clean up
clean:
	rm -f $(USER_EXEC) $(SERVER_EXEC)

.PHONY: all clean debug
