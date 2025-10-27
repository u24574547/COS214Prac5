CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Itests

# Normal program
SRCS_APP := $(wildcard *.cpp)
OBJS_APP := $(SRCS_APP:.cpp=.o)

# Tests (exclude main.cpp)
SRCS_TEST := $(filter-out main.cpp,$(wildcard *.cpp)) $(wildcard tests/*.cpp)
OBJS_TEST := $(SRCS_TEST:.cpp=.o)

all: app test_runner

app: $(OBJS_APP)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_APP)

test_runner: $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_TEST)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o tests/*.o app test_runner

tests: test_runner
	./test_runner