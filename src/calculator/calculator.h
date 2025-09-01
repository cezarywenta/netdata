// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef NETDATA_CALCULATOR_H
#define NETDATA_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>

// Calculator operation types
typedef enum {
    CALC_ADD,
    CALC_SUBTRACT,
    CALC_MULTIPLY,
    CALC_DIVIDE
} calc_operation_t;

// Function declarations
double calc_add(double a, double b);
double calc_subtract(double a, double b);
double calc_multiply(double a, double b);
double calc_divide(double a, double b);
double calc_operate(calc_operation_t op, double a, double b);
int calc_parse_and_calculate(const char* expression, double* result);

// Command line interface
int calc_main(int argc, char** argv);

#endif // NETDATA_CALCULATOR_H