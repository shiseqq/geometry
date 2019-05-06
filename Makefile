CC=g++
CFLAGS=-c -Wall -Werror -std=c++11
SOURCES=src/geometry.cpp src/cti.cpp src/intersect.cpp
OBJECTS=$(SOURCES:src/*.cpp=build/*.o)
EXECUTABLE=bin/geometry.exe
TEST_SOURCES=test/test.cpp
TEST_OBJECTS=build/intersect.o build/cti.o build/test.o
TEST_EXECUTABLE = bin/test.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ -std=c++11

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf build/*.o bin/*.exe bin/*.out

.PHONY : test
test : $(TEST_EXECUTABLE) $(TEST_OBJECTS)
	$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE) : $(TEST_OBJECTS)
	$(CC) $^ -o $@

build/%.o : test/%.cpp
	$(CC) $(CFLAGS) $< -o $@