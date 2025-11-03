# Combined Makefile - supports app, CLI, and unit tests

CXX      ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -g -O0
CPPFLAGS ?= -I. -Iinclude -Itests
LDFLAGS  ?=

# Core source files (business logic)
SRCS := Aggregate.cpp BasePlant.cpp Command.cpp Customer.cpp Day.cpp \
        DeadState.cpp Director.cpp DisplayBundle.cpp DyingState.cpp \
        Employee.cpp Fern.cpp FernExpert.cpp FernSupplier.cpp \
        Fertiliser.cpp Flowering.cpp FloweringExpert.cpp \
        FloweringSupplier.cpp FrostNet.cpp FrostReadyBuilder.cpp \
        Gardener.cpp GiftBuilder.cpp InquiryCommand.cpp Inventory.cpp \
        Iterator.cpp MatureState.cpp Moss.cpp MossExpert.cpp \
        MossSupplier.cpp NonFlowering.cpp NonfloweringExpert.cpp \
        NonFloweringSupplier.cpp OrderCommand.cpp Plant.cpp \
        PlantDecorator.cpp PlantIterator.cpp PlantState.cpp \
        ReadyForSale.cpp RefundCommand.cpp SeedlingState.cpp \
        SoldState.cpp Supplier.cpp TerrariumBuilder.cpp \
        TransactionCaretaker.cpp TransactionHistory.cpp \
        TransactionIterator.cpp TransactionMemento.cpp \
        UnplantedState.cpp Ribbon.cpp

# Entry point files
MAIN_APP := main.cpp
CLI_APP  := CLI.cpp

# Test files in tests/ directory
TEST_SRCS := $(wildcard tests/*.cpp)

BUILD_DIR := build
BIN_DIR   := bin

# Filter out missing source files
EXISTING_SRCS := $(wildcard $(SRCS))
MISSING_SRCS  := $(filter-out $(EXISTING_SRCS),$(SRCS))

ifneq ($(MISSING_SRCS),)
    $(warning The following source files were not found: $(MISSING_SRCS))
endif

# Object file lists
OBJS      := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(EXISTING_SRCS))
MAIN_OBJ  := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(MAIN_APP))
CLI_OBJ   := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(CLI_APP))
TEST_OBJS := $(patsubst tests/%.cpp,$(BUILD_DIR)/tests/%.o,$(TEST_SRCS))

# Binary outputs
BIN_APP  := $(BIN_DIR)/app
BIN_CLI  := $(BIN_DIR)/cli
BIN_TEST := $(BIN_DIR)/test_runner

# Default: build all targets
.PHONY: all
all: $(BIN_APP) $(BIN_CLI) $(BIN_TEST)

# Link main application
$(BIN_APP): $(OBJS) $(MAIN_OBJ) | $(BIN_DIR)
	@echo "Linking $@"
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(MAIN_OBJ)

# Link CLI application
$(BIN_CLI): $(OBJS) $(CLI_OBJ) | $(BIN_DIR)
	@echo "Linking $@"
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(CLI_OBJ)

# Link test runner (core objects + test objects, exclude CLI and main)
$(BIN_TEST): $(OBJS) $(TEST_OBJS) | $(BIN_DIR)
	@echo "Linking $@"
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(TEST_OBJS)

# Compile rule for core sources
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@echo "Compiling $<"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Compile rule for test sources
$(BUILD_DIR)/tests/%.o: tests/%.cpp | $(BUILD_DIR)/tests
	@echo "Compiling $<"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Ensure directories exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/tests:
	@mkdir -p $(BUILD_DIR)/tests

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Run targets
.PHONY: app cli test run
app: $(BIN_APP)
	@echo "Running $(BIN_APP) $(ARGS)"
	./$(BIN_APP) $(ARGS)

cli: $(BIN_CLI)
	@echo "Running $(BIN_CLI) $(ARGS)"
	./$(BIN_CLI) $(ARGS)

test: $(BIN_TEST)
	@echo "Running $(BIN_TEST) $(ARGS)"
	./$(BIN_TEST) $(ARGS)

run: app  # Default run target

# Valgrind targets
.PHONY: valgrind-app valgrind-cli valgrind-test
valgrind-app: $(BIN_APP)
	@echo "Valgrind: $(BIN_APP) $(ARGS)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN_APP) $(ARGS)

valgrind-cli: $(BIN_CLI)
	@echo "Valgrind: $(BIN_CLI) $(ARGS)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN_CLI) $(ARGS)

valgrind-test: $(BIN_TEST)
	@echo "Valgrind: $(BIN_TEST) $(ARGS)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN_TEST) $(ARGS)

# GDB targets
.PHONY: gdb-app gdb-cli gdb-test
gdb-app: $(BIN_APP)
	@echo "Starting gdb --args $(BIN_APP) $(ARGS)"
	gdb --args ./$(BIN_APP) $(ARGS)

gdb-cli: $(BIN_CLI)
	@echo "Starting gdb --args $(BIN_CLI) $(ARGS)"
	gdb --args ./$(BIN_CLI) $(ARGS)

gdb-test: $(BIN_TEST)
	@echo "Starting gdb --args $(BIN_TEST) $(ARGS)"
	gdb --args ./$(BIN_TEST) $(ARGS)

# Coverage analysis
.PHONY: gcov
gcov:
	@echo "Building with coverage flags..."
	$(MAKE) clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) --coverage" all
	@echo "Running tests to generate coverage data..."
	./$(BIN_TEST) $(ARGS)
	@mkdir -p coverage
	@echo "Running gcov..."
	@for f in $(EXISTING_SRCS) $(MAIN_APP) $(CLI_APP); do \
	  gcov -o $(BUILD_DIR) $$f >/dev/null || true; \
	done
	@for f in $(TEST_SRCS); do \
	  gcov -o $(BUILD_DIR)/tests $$f >/dev/null || true; \
	done
	@mv *.gcov coverage/ 2>/dev/null || true
	@echo "Coverage files are in coverage/ directory"

# Clean build artifacts and coverage files
.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR) coverage
	@rm -f *.gcda *.gcno *.gcov

# Full rebuild
.PHONY: rebuild
rebuild: clean all

# Help
.PHONY: help
help:
	@printf "Makefile targets:\n"
	@printf "  make                    - build all binaries (app, cli, test_runner)\n"
	@printf "  make app  ARGS=\"...\"    - build and run main application\n"
	@printf "  make cli  ARGS=\"...\"    - build and run CLI interface\n"
	@printf "  make test ARGS=\"...\"    - build and run unit tests\n"
	@printf "  make valgrind-app  ARGS=\"...\" - run app under valgrind\n"
	@printf "  make valgrind-cli  ARGS=\"...\" - run cli under valgrind\n"
	@printf "  make valgrind-test ARGS=\"...\" - run tests under valgrind\n"
	@printf "  make gdb-app  ARGS=\"...\" - start gdb for app\n"
	@printf "  make gdb-cli  ARGS=\"...\" - start gdb for cli\n"
	@printf "  make gdb-test ARGS=\"...\" - start gdb for tests\n"
	@printf "  make gcov ARGS=\"...\"     - build with coverage, run tests, produce .gcov\n"
	@printf "  make clean              - remove all build artifacts\n"
	@printf "  make rebuild            - clean then build all\n"
	@printf "\nExamples:\n"
	@printf "  make test ARGS=\"--verbose\"\n"
	@printf "  make cli ARGS=\"--input data.txt\"\n"
	@printf "  make valgrind-test\n"