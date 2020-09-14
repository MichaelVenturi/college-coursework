// Michael Venturi, lab 1
#include <iostream> 
#include <string>   
#include "Bag.h"    

using namespace std;

void sortFragile(Bag<string>& store, Bag<string>& fragile);
int removeCount(Bag<string>& source, string target);
int main()
{

	Bag<string> storeBag;
	Bag<string> fragileBag;

	string input;

	cout << "Enter the groceries you would like to add to the bag.  Enter \"done\" when you are finished\n";
	while (storeBag.getCurrentSize() != 6) {
		cin >> input;
		if (input == "done" || input == "Done") {
			break;
		}
		else {
			storeBag.add(input);
		}
	}
	
	sortFragile(storeBag, fragileBag);

	string remove;

	cout << "Enter item(s) you would like to remove.  Enter \"exit\" when you are done:\n";
	while (!storeBag.isEmpty()) {
		cin >> remove;
		if (remove == "exit" || remove == "Exit") {
			break;
		}
		else {
			cout << removeCount(storeBag, remove) << " item(s) were removed\n";
		}
	}
	cout << endl;

	cout << "***STORE BAG***\n";
	storeBag.displayBagContents();
	cout << "***FRAGILE BAG***\n";
	fragileBag.displayBagContents();

	return 0;
};
void sortFragile(Bag<string>&store, Bag<string>&fragile) {	// Fragile items are eggs and bread
	while (store.contains("eggs")) {
		store.remove("eggs");
		fragile.add("eggs");
	}
	while (store.contains("Eggs")) {
		store.remove("Eggs");
		fragile.add("eggs");
	}
	while (store.contains("bread")) {
		store.remove("bread");
		fragile.add("bread");
	}
	while (store.contains("Bread")) {
		store.remove("Bread");
		fragile.add("bread");
	}
}
int removeCount(Bag<string>& source, string target) {
	int count=0;

	while (source.contains(target)) {
		source.remove(target);
		count++;
	}

	return count;
}

