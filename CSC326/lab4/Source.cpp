#include <iostream>
#include <string>
#include <fstream>

#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;


void selectionSort(ListInterface<int>& list);

int main() {

	ifstream inFile;
	inFile.open("data.txt");
	if (!inFile) {
		exit(0);
	}

	ArrayList<int> arrListInt;
	LinkedList<int> linkListInt;
	
	int position = 0;
	int value;
	while (!inFile.eof()) {
		position++;
		inFile >> value;
		arrListInt.insert(position, value);
		linkListInt.insert(position, value);
	}

	cout << "Array list: \n";
	arrListInt.print();
	cout << "Linked list: \n";
	linkListInt.print();

	selectionSort(arrListInt);
	selectionSort(linkListInt);

	cout << "Array list sorted: \n";
	arrListInt.print();
	cout << "Linked list sorted: \n";
	linkListInt.print();


	inFile.close();
	return 0;
}

void selectionSort(ListInterface<int>& list) {
	if (list.getLength() <= 1) {
		return;
	}

	try {
		int length = list.getLength();
		int curIndex, compareIndex, lowestIndex,
			curValue, compareValue, lowestValue;

		for (int i = 1; i < length; i++) {
			curIndex = i;
			lowestIndex = curIndex;  // assume the current index is the lowest value
			curValue = list.getEntry(i);
			lowestValue = curValue;
			// compare to the rest of the list
			for (int j = curIndex + 1; j <= length; j++) {
				compareIndex = j;
				compareValue = list.getEntry(j);
				// if another value in the list is lower, set that to the lowest number
				if (compareValue < lowestValue) {
					lowestValue = compareValue;
					lowestIndex = compareIndex;
				}
			}
			// if the lowest number is not the current number, swap their places
			if (lowestIndex != curIndex) {
				list.replace(curIndex, lowestValue);
				list.replace(lowestIndex, curValue);
			}
		}
	}
	catch (PrecondViolatedExcep& excep) {
		cout << excep.what() << endl;
	}
}