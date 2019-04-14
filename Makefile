CC=g++
CFLAGS=-c -Wall -Werror -std=c++11
SOURCES=src/geometry.cpp src/cti.cpp
OBJECTS=$(SOURCES:src/*.cpp=build/*.o)
EXECUTABLE=bin/geometry.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -std=c++11

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf build/*.o bin/*.exe