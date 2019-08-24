CC = g++
WARNINGS = -Wall -Wextra -Wpedantic
OPTIONS = -g -std=c++11 -I./ $(WARNINGS) 
BUILD_DIR = build
TEST_DIR = test
SRC_DIR = src
INC_DIR = include

.PHONY: clean

test_priority_queue.o: $(TEST_DIR)/test_priority_queue.cpp
	$(CC) $(OPTIONS) -c $< -o $(BUILD_DIR)/$@

test: test_priority_queue.o
	$(CC) $(OPTIONS) $(addprefix $(BUILD_DIR)/,$^) -o $@.bin

clean:
	rm test.bin
	rm -f $(BUILD_DIR)/*