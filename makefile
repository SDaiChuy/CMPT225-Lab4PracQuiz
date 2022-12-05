all: BSTtd

BSTtd: BSTTestDriver.o BST.o UnableToInsertException.o 
	g++ -Wall -o BSTtd BSTTestDriver.o BST.o UnableToInsertException.o

BSTTestDriver.o: BSTTestDriver.cpp
	g++ -Wall -c BSTTestDriver.cpp
		
BST.o: BST.cpp
	g++ -Wall -c BST.cpp

UnableToInsertException.o: UnableToInsertException.h UnableToInsertException.cpp
	g++ -Wall -c UnableToInsertException.cpp

clean:
	rm -f BSTtd *.o