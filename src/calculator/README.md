# Calculator Module

This directory contains a simple calculator application for basic arithmetic operations.

## Features

- **Basic arithmetic operations**: Addition (+), Subtraction (-), Multiplication (*), Division (/)
- **Interactive mode**: Start calculator without arguments for interactive session
- **Command-line mode**: Pass expression as argument for single calculation
- **Error handling**: Division by zero detection and invalid input validation
- **Floating point support**: Works with decimal numbers
- **Multiple multiplication symbols**: Supports *, x, and X for multiplication

## Usage

### Interactive Mode
```bash
./calculator
```

Start the calculator and enter expressions interactively. Type "quit" or "exit" to exit.

Example session:
```
Simple Calculator
Usage: calculator "number operator number"
Supported operators: + - * /

Enter expressions (or 'quit' to exit):
> 5 + 3
Result: 8
> 12 * 7
Result: 84
> 25 / 5
Result: 5
> 10 - 3.5
Result: 6.5
> quit
```

### Command-line Mode
```bash
./calculator "5 + 3"
./calculator "12.5 * 2"
./calculator "100 / 25"
```

## Building

### Standalone Build
```bash
make clean
make
```

### Testing
```bash
make test
```

### CMake Build (with Netdata)
The calculator is integrated into the Netdata build system and will be built as:
- `netdata-calculator` - the main calculator executable
- `netdata-calculator-test` - the test executable

## Files

- **calculator.h** - Header file with function declarations
- **calculator.c** - Core calculator implementation
- **main.c** - Command-line interface
- **test_calculator.c** - Comprehensive test suite
- **Makefile** - Standalone build system
- **CMakeLists.txt** - CMake integration for Netdata build system

## Testing

The test suite includes:
- Basic arithmetic operations testing
- Error handling verification (division by zero, invalid input)
- Expression parsing validation
- Alternative operator symbol support

All tests use assertions and will fail if any functionality is broken.