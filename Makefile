CFLAGS = -Wall -Werror

all: bin/geometry.exe

bin/geometry.exe: src/geometry.cpp src/cti.cpp
	g++ $(CFLAGS) -o bin/geometry.exe src/geometry.cpp src/cti.cpp

clean:
	rm -rf *.o *.exe