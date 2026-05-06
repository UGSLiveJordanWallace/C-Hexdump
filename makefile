CXX = gcc
CXXFLAGS = -Wall -g

build: main.c
	$(CXX) $(CXXFLAGS) main.c -o build

debug:
	gdb --args ./build binary.out

val:
	valgrind ./build binary.out
