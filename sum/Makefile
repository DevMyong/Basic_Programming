all: sum

sum: main.o sum.o
	g++ -o sum main.o sum.o

main.o: sum.h main.cpp

sum.o : sum.h sum.cpp

clean:
	rm -f sum
	rm -f *.o
