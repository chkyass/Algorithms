CC = g++
WARNINGS = -Wall -Wextra -Wpedantic
OPTIMIZATION = -O3
LINKS = include/test_main.o
ERRORS = -ferror-limit=2
OPTIONS = -std=c++11 -I./ -ferror-limit=2 $(ERRORS) $(WARNINGS) $(OPTIMIZATION) $(LINKS)
BIN_DIR = bin
TEST_DIR = test
SRC_DIR = src
INC_DIR = include

.PHONY: clean

compile-test-obj:
	$(CC) -std=c++11 -I./ test/test_main.cpp -c -o include/test_main.o

heap:
	$(CC) $(OPTIONS) $(TEST_DIR)/test_priority_queue.cpp -o $(BIN_DIR)/$@.bin

bst:
	$(CC) $(OPTIONS) $(TEST_DIR)/test_bst.cpp -o $(BIN_DIR)/$@.bin

avl:
	$(CC) $(OPTIONS)  $(TEST_DIR)/test_avl.cpp -o $(BIN_DIR)/$@.bin

sort: 
	$(CC) $(OPTIONS)  $(TEST_DIR)/test_sort.cpp -o $(BIN_DIR)/$@.bin

bench_sort:
	$(CC) -std=c++11 -O3 -L/usr/local/Cellar/boost/1.71.0/lib  -lpthread -lbenchmark benchmark/$@.cpp -o benchmark/$@.bin

hashtable:
	$(CC) $(OPTIONS)  $(TEST_DIR)/test_hashtable.cpp -o $(BIN_DIR)/$@.bin; ./$(BIN_DIR)/$@.bin

graph:
	$(CC) $(OPTIONS)  $(TEST_DIR)/test_graph.cpp -o $(BIN_DIR)/$@.bin ; ./$(BIN_DIR)/$@.bin

clean:
	rm bin/*.bin
