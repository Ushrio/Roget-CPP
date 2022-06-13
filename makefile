CC=clang++
CFLAGS=-g -O3 -std=c++17
DEPS=src/lib.hpp
OBJ=src/roget.o src/lib.o src/lib/algorithms/naive.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

roget: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f src/*.o roget
