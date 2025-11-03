# Plant Nursery Management System

A C++ application for managing a plant nursery with inventory, transactions, customers, and employees.

## Prerequisites

- C++ Compiler (g++ with C++11 support)
- GNU Make

## Quick Start

### Build Everything

```bash
make
```

This compiles:
- `bin/cli` - Command-line interface
- `bin/test_runner` - Unit test suite

## Running the Application

### CLI Interface

```bash
make cli
```

### Unit Tests

```bash
make test
```

## Additional Commands

```bash
# Clean build artifacts
make clean

# Rebuild everything
make rebuild

# Show all available commands
make help
```

## Project Structure

```
project/
├── *.cpp                    # Core source and header files
├── *.h                      # Header files (in root directory)
├── CLI.cpp                  # CLI entry point
├── tests/                   # Unit test files
├── build/                   # Generated object files
└── bin/                     # Compiled executables
```