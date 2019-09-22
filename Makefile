CC = g++
WARNINGS = -Wall -Wextra -Wpedantic
OPTIMIZATION = -O3
TEST_LINK = include/test-main.o
OPTIONS = -std=c++11 -I./ $(WARNINGS) $(OPTIMIZATION) $(TEST_LINK)
BIN_DIR = bin
TEST_DIR = test
SRC_DIR = src
INC_DIR = include

.PHONY: clean

compile-test-obj:
$(CC) -std=c++11 -I./ test/test-main.cpp -c -o include/test-main.o

heap:
	$(CC) $(OPTIONS) $(TEST_DIR)/test_priority_queue.cpp -o $(BIN_DIR)/$@.bin

bst:
	$(CC) $(OPTIONS) $(TEST_DIR)/test_bst.cpp -o $(BIN_DIR)/$@.bin

avl:
	$(CC) $(OPTIONS)  $(TEST_DIR)/test_avl.cpp -o $(BIN_DIR)/$@.bin

sort: 
	$(CC) $(OPTIONS)  $(TEST_DIR)/test_sort.cpp -o $(BIN_DIR)/$@.bin

run:
	./sort.bin

clean:
	rm bin/*.bin
