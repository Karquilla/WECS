# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Iinclude -std=c++17

# Directories
INCDIR = include
SRCDIR = src
OBJDIR = obj

# Target executables
TARGET = wecs
RUN_TARGET = main

# Source files and object files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Create obj directory if it doesn't exist
$(shell mkdir -p $(OBJDIR))

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile run_events target
main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(RUN_TARGET) $(OBJS) -lstdc++fs

# Clean target
clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(RUN_TARGET)

# Phony targets
.PHONY: all clean run_events