# Makefile - single-directory project with test and CLI run modes

CXX      ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -g -O0
CPPFLAGS ?= -I.
LDFLAGS  ?=

# Provided by you - with Observer and Day added
SRCS := Aggregate.cpp BasePlant.cpp Command.cpp Customer.cpp Day.cpp DeadState.cpp Director.cpp DisplayBundle.cpp DyingState.cpp Employee.cpp Fern.cpp FernExpert.cpp FernSupplier.cpp Fertiliser.cpp Flowering.cpp FloweringExpert.cpp FloweringSupplier.cpp FrostNet.cpp FrostReadyBuilder.cpp Gardener.cpp GiftBuilder.cpp InquiryCommand.cpp Inventory.cpp Iterator.cpp MatureState.cpp Moss.cpp MossExpert.cpp MossSupplier.cpp NonFlowering.cpp NonfloweringExpert.cpp NonFloweringSupplier.cpp OrderCommand.cpp Plant.cpp PlantDecorator.cpp PlantIterator.cpp PlantState.cpp ReadyForSale.cpp RefundCommand.cpp SeedlingState.cpp SoldState.cpp Supplier.cpp TerrariumBuilder.cpp TransactionCaretaker.cpp TransactionHistory.cpp TransactionIterator.cpp TransactionMemento.cpp UnplantedState.cpp Ribbon.cpp

TEST := main.cpp
CLI  := CLI.cpp

BUILD_DIR := build
BIN_DIR   := bin

# Filter out source files that don't exist to avoid errors
EXISTING_SRCS := $(wildcard $(SRCS))
MISSING_SRCS := $(filter-out $(EXISTING_SRCS),$(SRCS))

ifneq ($(MISSING_SRCS),)
    $(warning The following source files were not found: $(MISSING_SRCS))
endif

# object lists - only for existing sources
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(EXISTING_SRCS))
TEST_OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TEST))
CLI_OBJ  := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(CLI))

BIN_TEST := $(BIN_DIR)/test
BIN_CLI  := $(BIN_DIR)/cli

# Default: build both (test and cli)
.PHONY: all
all: $(BIN_TEST) $(BIN_CLI)

# Link targets
$(BIN_TEST): $(OBJS) $(TEST_OBJ) | $(BIN_DIR)
	@echo "Linking $@"
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(TEST_OBJ)

$(BIN_CLI): $(OBJS) $(CLI_OBJ) | $(BIN_DIR)
	@echo "Linking $@"
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(CLI_OBJ)

# Compile rule for any .cpp -> build/%.o
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@echo "Compiling $<"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Ensure directories exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Run test (build then run)
.PHONY: test
test: $(BIN_TEST)
	@echo "Running $(BIN_TEST) $(ARGS)"
	./$(BIN_TEST) $(ARGS)

# Run CLI (build then run)
.PHONY: cli
cli: $(BIN_CLI)
	@echo "Running $(BIN_CLI) $(ARGS)"
	./$(BIN_CLI) $(ARGS)

# Valgrind targets
.PHONY: valgrind-test valgrind-cli
valgrind-test: $(BIN_TEST)
	@echo "Valgrind: $(BIN_TEST) $(ARGS)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN_TEST) $(ARGS)

valgrind-cli: $(BIN_CLI)
	@echo "Valgrind: $(BIN_CLI) $(ARGS)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN_CLI) $(ARGS)

# GDB targets
.PHONY: gdb-test gdb-cli
gdb-test: $(BIN_TEST)
	@echo "Starting gdb --args $(BIN_TEST) $(ARGS)"
	gdb --args ./$(BIN_TEST) $(ARGS)

gdb-cli: $(BIN_CLI)
	@echo "Starting gdb --args $(BIN_CLI) $(ARGS)"
	gdb --args ./$(BIN_CLI) $(ARGS)

# Build with coverage, run test, produce .gcov in coverage/
.PHONY: gcov
gcov:
	@echo "Building with coverage flags..."
	$(MAKE) clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) --coverage" all
	@echo "Running test to generate coverage data..."
	./$(BIN_TEST) $(ARGS)
	@mkdir -p coverage
	@echo "Running gcov..."
	@for f in $(EXISTING_SRCS) $(TEST) $(CLI); do \
	  gcov -o $(BUILD_DIR) $$f >/dev/null || true; \
	done
	@mv *.gcov coverage/ 2>/dev/null || true
	@echo "Coverage files are in coverage/ (look for .gcov and .gcda/.gcno files)"

# Convenience: run default (alias to test)
.PHONY: run
run: test

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
	@printf "  make                 - build both test and cli (default)\n"
	@printf "  make test ARGS=\"...\" - build and run test (main.cpp)\n"
	@printf "  make cli  ARGS=\"...\" - build and run CLI (CLI.cpp)\n"
	@printf "  make valgrind-test ARGS=\"...\" - run test under valgrind\n"
	@printf "  make valgrind-cli  ARGS=\"...\" - run cli under valgrind\n"
	@printf "  make gdb-test ARGS=\"...\" - start gdb for test\n"
	@printf "  make gdb-cli  ARGS=\"...\" - start gdb for cli\n"
	@printf "  make gcov ARGS=\"...\" - build with coverage, run test, produce .gcov\n"
	@printf "  make clean\n"
	@printf "\nExamples:\n"
	@printf "  make test ARGS=\"--input foo.txt\"\n"
	@printf "  make cli ARGS=\"--port 1234\"\n"