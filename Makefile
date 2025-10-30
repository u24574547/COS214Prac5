CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Source files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# Default target
all: app

# Compile the normal app
app: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f *.o app

run:
	./app