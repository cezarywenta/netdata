// SPDX-License-Identifier: GPL-3.0-or-later

#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Basic arithmetic operations
double calc_add(double a, double b) {
    return a + b;
}

double calc_subtract(double a, double b) {
    return a - b;
}

double calc_multiply(double a, double b) {
    return a * b;
}

double calc_divide(double a, double b) {
    if (b == 0.0) {
        fprintf(stderr, "Error: Division by zero\n");
        return NAN;
    }
    return a / b;
}

// Generic operation function
double calc_operate(calc_operation_t op, double a, double b) {
    switch (op) {
        case CALC_ADD:
            return calc_add(a, b);
        case CALC_SUBTRACT:
            return calc_subtract(a, b);
        case CALC_MULTIPLY:
            return calc_multiply(a, b);
        case CALC_DIVIDE:
            return calc_divide(a, b);
        default:
            fprintf(stderr, "Error: Unknown operation\n");
            return NAN;
    }
}

// Simple expression parser for "a op b" format
int calc_parse_and_calculate(const char* expression, double* result) {
    if (!expression || !result) {
        return -1;
    }

    double a, b;
    char op;
    
    // Parse format: "number operator number"
    int parsed = sscanf(expression, "%lf %c %lf", &a, &op, &b);
    if (parsed != 3) {
        fprintf(stderr, "Error: Invalid expression format. Use: 'number operator number'\n");
        return -1;
    }

    calc_operation_t operation;
    switch (op) {
        case '+':
            operation = CALC_ADD;
            break;
        case '-':
            operation = CALC_SUBTRACT;
            break;
        case '*':
        case 'x':
        case 'X':
            operation = CALC_MULTIPLY;
            break;
        case '/':
            operation = CALC_DIVIDE;
            break;
        default:
            fprintf(stderr, "Error: Unsupported operator '%c'. Use +, -, *, or /\n", op);
            return -1;
    }

    *result = calc_operate(operation, a, b);
    
    // Check for calculation errors (like division by zero)
    if (isnan(*result)) {
        return -1;
    }
    
    return 0;
}

// Command line interface
int calc_main(int argc, char** argv) {
    printf("Simple Calculator\n");
    printf("Usage: calculator \"number operator number\"\n");
    printf("Supported operators: + - * /\n\n");

    if (argc < 2) {
        // Interactive mode
        char input[256];
        printf("Enter expressions (or 'quit' to exit):\n");
        
        while (1) {
            printf("> ");
            if (!fgets(input, sizeof(input), stdin)) {
                break;
            }
            
            // Remove newline
            size_t len = strlen(input);
            if (len > 0 && input[len-1] == '\n') {
                input[len-1] = '\0';
            }
            
            // Check for quit command
            if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
                break;
            }
            
            double result;
            if (calc_parse_and_calculate(input, &result) == 0) {
                printf("Result: %.6g\n", result);
            }
        }
    } else {
        // Command line argument mode
        char* expression = argv[1];
        double result;
        
        if (calc_parse_and_calculate(expression, &result) == 0) {
            printf("Result: %.6g\n", result);
            return 0;
        } else {
            return 1;
        }
    }
    
    return 0;
}