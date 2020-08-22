#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class textLines {
public:
	void readList();

	void removeLast();
	void addLine(const string& line);
	void emptyList();
	void getUsed();
	void combineList(const textLines& source);

	textLines& operator=(const textLines& source);	 // Overload Assignment Operator
	textLines(const textLines& source);				 // Copy constructor
	textLines(ifstream&);							 // Takes file as parameter
	textLines(int);									 // Takes int as parameter
	~textLines();					
private:
	int capacity;
	int used;
	string* list;
};

// FILE constructor
textLines::textLines(ifstream& File) {
	int count = 0;
	string line;
	while (getline(File, line)) {		// Counts number of lines in file
		count++;
	}
	capacity = count * 2;
	cout << "Constructing list of capacity: " << capacity << " . . .\n";
	list = new string[capacity];
	File.clear();						// Returns inFile to the top of the file for the next loop
	File.seekg(0, ios::beg);
	cout << "List constructed with lines:\n";
	for (int i = 0; i < count; i++) {	// Reads file into array
		getline(File, list[i]);
		cout << list[i] << " | ";
	}
	cout << "\n\n";
	used = count;
}

// EMPTY constructor
textLines::textLines(int size) {
	capacity = size;
	cout << "Constructing list of capacity: " << capacity << " . . .\n";
	list = new string[capacity];
	cout << "Empty list constructed\n\n";
	used = 0;
}

// COPY constructor
textLines::textLines(const textLines& source) {
	cout << "Copy constructor called\n";
	capacity = source.capacity;
	used = source.used;
	list = new string[capacity];
	copy(source.list, source.list + used, list);
	cout << "List of capacity: " << capacity << " created with lines:\n";
	for (int i = 0; i < used; i++) {
		cout << list[i] << " | ";
	}
	cout << "\n\n";
}

// Destructor
textLines::~textLines() {
	cout << "Destructor called\n";
	delete[] list;
}

// Overload Assignment
textLines& textLines::operator=(const textLines& source) {
	cout << "Overload assignment called\n";
	if (this == &source) {
		return *this;		
	}
		this->capacity = source.capacity;
		this->used = source.used;
		copy(source.list, source.list + used, this->list);
		cout << "List copied\n\n";
}

// Read list
void textLines::readList() {			
	cout << "Reading list:\n";
	for (int i = 0; i < used; i++) {
		cout << list[i] << " | ";
	}
	cout << "\n\n";
}

// Remove and return last line
void textLines::removeLast() {
	cout << "Reading last line of list:\n";
	cout << list[used - 1] << endl;
	list[used - 1].clear();		// Empties the last used space in the array
	cout << "Last line cleared\n\n";
	used--;
}

// Insert line
void textLines::addLine(const string& line) {
	if (used == capacity) {
		cout << "List full.  Expanding . . .\n";
		string* tempList = new string[used];
		copy(list, list + used, tempList);
		delete[] list;
		capacity = used * 2;
		list = new string[capacity];
		copy(tempList, tempList + used, list);
		delete[] tempList;
		cout << "List capacity expanded to: " << capacity << "\n\n";
	}
	list[used] = line;
	used++;
}

// Empty list
void textLines::emptyList() {
	cout << "Emptying list . . .\n";
	for (int i = 0; i < capacity; i++) {
		list[i].clear();
	}
	cout << "List emptied\n\n";
	used = 0;
}

// Return number of lines
void textLines::getUsed() {	
	cout << "This list has " << used << " lines\n\n";	
}

// Combine lists
void textLines::combineList(const textLines& source) {
	string* combine;
	int doubleCap = capacity + source.capacity;
	int doubleUsed;
	combine = new string[doubleCap];
	for (int i = 0; i < used; i++) {			// Copies all the values from the initial list first
		combine[i] = list[i];
	}
	cout << "Combining lists . . .\n";
	doubleUsed = used;
	for (int j = 0; j < source.used; j++) {
		for (int k = 0; k < used; k++) {
			if (combine[k] == source.list[j]) {
				break;
			}
			if (k == used - 1) {				// If the loop makes it to the last iteration without breaking, there are no duplicates
				combine[doubleUsed] = source.list[j];
				doubleUsed++;
			}
		}
	}
	cout << "Lists combined without duplicates.  Here is the combined list:\n";
	for (int z = 0; z < doubleUsed; z++) {
		cout << combine[z] << " | ";
	}
	cout << "\n\n";
}

int main() {

	ifstream inFile;
	inFile.open("lines.txt");
	if (!inFile) {
		exit(0);
	}
	
	textLines A(inFile);
	textLines B(6);
	
	B.addLine("See ya");
	B.addLine("Later");
	B.addLine("Guy");

	A.combineList(B);

	A.addLine("You");
	A.addLine("Are");
	A.addLine("A");
	A.addLine("Dunce");
	A.readList();

	textLines C(A);
	C.removeLast();

	C = B;
	C.getUsed();
	C.emptyList();
	C.getUsed();
	
	inFile.close();
	system("pause");
	return 0;
}
