// SPDX-License-Identifier: GPL-3.0-or-later

#include "calculator.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

// Simple test framework using assert
void test_basic_operations() {
    printf("Testing basic operations...\n");
    
    // Test addition
    assert(calc_add(2.0, 3.0) == 5.0);
    assert(calc_add(-1.0, 1.0) == 0.0);
    assert(calc_add(0.0, 0.0) == 0.0);
    
    // Test subtraction
    assert(calc_subtract(5.0, 3.0) == 2.0);
    assert(calc_subtract(1.0, 1.0) == 0.0);
    assert(calc_subtract(0.0, 5.0) == -5.0);
    
    // Test multiplication
    assert(calc_multiply(2.0, 3.0) == 6.0);
    assert(calc_multiply(-2.0, 3.0) == -6.0);
    assert(calc_multiply(0.0, 100.0) == 0.0);
    
    // Test division
    assert(calc_divide(6.0, 2.0) == 3.0);
    assert(calc_divide(1.0, 1.0) == 1.0);
    assert(calc_divide(-6.0, 2.0) == -3.0);
    
    // Test division by zero returns NaN
    assert(isnan(calc_divide(1.0, 0.0)));
    
    printf("Basic operations tests passed!\n");
}

void test_operation_function() {
    printf("Testing operation function...\n");
    
    assert(calc_operate(CALC_ADD, 2.0, 3.0) == 5.0);
    assert(calc_operate(CALC_SUBTRACT, 5.0, 3.0) == 2.0);
    assert(calc_operate(CALC_MULTIPLY, 2.0, 3.0) == 6.0);
    assert(calc_operate(CALC_DIVIDE, 6.0, 2.0) == 3.0);
    
    printf("Operation function tests passed!\n");
}

void test_expression_parser() {
    printf("Testing expression parser...\n");
    
    double result;
    
    // Test valid expressions
    assert(calc_parse_and_calculate("2 + 3", &result) == 0);
    assert(result == 5.0);
    
    assert(calc_parse_and_calculate("10 - 4", &result) == 0);
    assert(result == 6.0);
    
    assert(calc_parse_and_calculate("3 * 4", &result) == 0);
    assert(result == 12.0);
    
    assert(calc_parse_and_calculate("8 / 2", &result) == 0);
    assert(result == 4.0);
    
    // Test alternative multiplication symbols
    assert(calc_parse_and_calculate("3 x 4", &result) == 0);
    assert(result == 12.0);
    
    // Test invalid expressions
    assert(calc_parse_and_calculate("2 +", &result) == -1);
    assert(calc_parse_and_calculate("+ 3", &result) == -1);
    assert(calc_parse_and_calculate("2 # 3", &result) == -1);
    
    // Test division by zero
    assert(calc_parse_and_calculate("5 / 0", &result) == -1);
    
    printf("Expression parser tests passed!\n");
}

int main() {
    printf("Running calculator tests...\n\n");
    
    test_basic_operations();
    test_operation_function();
    test_expression_parser();
    
    printf("\nAll tests passed! Calculator is working correctly.\n");
    return 0;
}