#include "sequence.cpp"
#include <iostream>
#include <string>

using namespace std;

void menu(sequence<int>&);
int main() {

	sequence<int> mySequence(5);
	mySequence.push_back(0);
	mySequence.push_back(0);
	mySequence.push_back(7);

	menu(mySequence);

	return 0;
}

void menu(sequence<int>& mySequence) {
	bool active = true;
	while (active) {
		int input, position, entry;

		cout << "****************************************\n";
		if (mySequence.empty()) { cout << "Your current sequence is empty\n"; } 
		else {
			cout << "Your current sequence is:\n"; 
			mySequence.print();
		}
		cout << "Enter the number of the option you want to do:\n"
			"1. Return an element at a position\n"					// at
			"2. Overwrite an element at a position\n"				// set
			"3. Insert an element at a position\n"					// insert
			"4. Add an element to the end of your sequence\n"		// push_back
			"5. Remove an element at a position\n"					// remove_current
			"6. Exit\n";											
		cin >> input;
		switch (input) {
		case 1:
			cout << "Enter the position: "; cin >> position;
			cout << mySequence.at(position) << endl;
			break;

		case 2:
			cout << "Enter the position: "; cin >> position;
			cout << "Enter the replacement: "; cin >> entry;
			mySequence.set(entry, position);
			break;
		case 3:
			cout << "Enter the position: "; cin >> position;
			cout << "Enter the addition: "; cin >> entry;
			mySequence.insert(entry, position);
			break;
		case 4:
			cout << "Enter the addition: "; cin >> entry;
			mySequence.push_back(entry);
			break;
		case 5:
			cout << "Enter the position; "; cin >> position;
			mySequence.remove_current(position);
			break;
		case 6:
			cout << "Your final sequence is: \n";
			mySequence.print();
			cout << "bye bye :)\n";
			active = false;
			break;
		default:
			cout << "Invalid input.  Please try again\n";
			break;
		}
	}
}
