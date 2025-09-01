# SPDX-License-Identifier: GPL-3.0-or-later

# Calculator module
set(CALCULATOR_FILES
    calculator.c
    calculator.h
)

add_library(calculator_lib STATIC ${CALCULATOR_FILES})
target_link_libraries(calculator_lib m)

# Calculator executable
add_executable(netdata-calculator main.c)
target_link_libraries(netdata-calculator calculator_lib)

# Calculator test executable
add_executable(netdata-calculator-test test_calculator.c)
target_link_libraries(netdata-calculator-test calculator_lib)