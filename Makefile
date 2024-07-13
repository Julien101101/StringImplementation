# Define the compiler
CC = g++

# Define compiler flags
CXXFLAGS = -std=c++11 -Wall

# Define the target executable
TARGET = hw04

# Define source files
SRCS = hw04.cpp hw04f.cpp

# Define object files
OBJS = $(SRCS:.cpp=.o)

# Rule to build the target executable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.cpp hw04.h
	$(CC) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
