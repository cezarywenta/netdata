# Simple Makefile for the calculator

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS = -lm

# Source files
CALCULATOR_SRCS = calculator.c
MAIN_SRCS = main.c
TEST_SRCS = test_calculator.c

# Object files
CALCULATOR_OBJS = $(CALCULATOR_SRCS:.c=.o)
MAIN_OBJS = $(MAIN_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Targets
CALCULATOR_BIN = calculator
TEST_BIN = test_calculator

.PHONY: all clean test

all: $(CALCULATOR_BIN) $(TEST_BIN)

$(CALCULATOR_BIN): $(CALCULATOR_OBJS) $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(TEST_BIN): $(CALCULATOR_OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f *.o $(CALCULATOR_BIN) $(TEST_BIN)

install: $(CALCULATOR_BIN)
	cp $(CALCULATOR_BIN) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(CALCULATOR_BIN)