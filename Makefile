# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
USER_DIR = src/user
SERVER_DIR = src/server

# Find all cpp files in the user and server directories
USER_SOURCES = $(wildcard $(USER_DIR)/*.cpp)
SERVER_SOURCES = $(wildcard $(SERVER_DIR)/*.cpp)

# Executable names
USER_EXEC = ./user
SERVER_EXEC = ./server

# Default target
all: debug $(USER_EXEC) $(SERVER_EXEC)

# Rules for building user and server executables
$(USER_EXEC):
	$(CXX) $(CXXFLAGS) $(USER_SOURCES) -o $(USER_EXEC)

$(SERVER_EXEC):
	$(CXX) $(CXXFLAGS) $(SERVER_SOURCES) -o $(SERVER_EXEC)

# Debugging
debug:
	@echo "User Sources: $(USER_SOURCES)"
	@echo "Server Sources: $(SERVER_SOURCES)"

# Clean up
clean:
	rm -f $(USER_EXEC) $(SERVER_EXEC)

.PHONY: all clean debug
