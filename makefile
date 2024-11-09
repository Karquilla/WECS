# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Iinclude

# Directories
INCDIR = include
SRCDIR = src
OBJDIR = obj

# Target executable
TARGET = wecs

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

# Clean target
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean