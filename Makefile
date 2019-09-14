CC = g++
WARNINGS = -Wall -Wextra -Wpedantic
OPTIONS = -g -std=c++11 -I./ $(WARNINGS) 
BUILD_DIR = build
TEST_DIR = test
SRC_DIR = src
INC_DIR = include

.PHONY: clean

priority_queue:
	$(CC) $(OPTIONS) $(TEST_DIR)/test_priority_queue.cpp -o $@.bin

bst:
	$(CC) $(OPTIONS) $(TEST_DIR)/test_bst.cpp -o $@.bin

avl:
	$(CC) $(OPTIONS) -o3 $(TEST_DIR)/test_avl.cpp -o $@.bin

run:
	./avl.bin

clean:
	rm *.bin
	rm -f $(BUILD_DIR)/*