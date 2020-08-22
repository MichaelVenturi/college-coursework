#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class GChar
{
public:
	static const int DEFAULT_CAPACITY = 5;

	//constructor
	GChar(string name = "john", int capacity = DEFAULT_CAPACITY);

	//copy constructor
	GChar(const GChar& source);

	//Overload Assignment
	GChar& operator=(const GChar& source);

	//Destructor
	~GChar();

	//Insert a New Tool
	void insert(const std::string& toolName);

private:
	//data members
	string name;
	int capacity;
	int used;
	string* toolHolder;
};

//constructor
GChar::GChar(string n, int cap)
{
	name = n;
	capacity = cap;
	used = 0;
	toolHolder = new string[cap];

	cout << "Character Created:" << endl;
	cout << "Name: " << name << endl;
	cout << "Capacity: " << capacity << endl;
	cout << "Tools Used: " << used << endl;
	for (int i = 0; i < used; i++)
	{
		cout << toolHolder[i] << " | ";
	}
}

//copy constructor
GChar::GChar(const GChar& source)
{
	cout << "Copy Constructor Called." << endl;
	cout << "Character Created:" << endl;

	name = source.name;
	capacity = source.capacity;
	used = source.used;
	toolHolder = new string[source.capacity];

	copy(source.toolHolder, source.toolHolder + used, toolHolder);
	cout << "Name: " << name << endl;
	cout << "Capacity: " << capacity << endl;
	cout << "Tools Used: " << used << endl;
	for (int i = 0; i < used; i++)
	{
		cout << toolHolder[i] << " | ";
	}
}

//Overload Assignment
GChar& GChar::operator=(const GChar& source)
{
	cout << "Overload Assignment Called." << endl;
	//Check for self assignment
	//c1=c1
	if (this == &source)
	{
		return *this;
	}
	this->name = source.name;
	this->capacity = source.capacity;
	used = source.used;
	copy(source.toolHolder, source.toolHolder + used, this->toolHolder);
	cout << "Character Copied:" << endl;
	cout << "Name: " << name << endl;
	cout << "Capacity: " << capacity << endl;
	cout << "Tools Used: " << used << endl;
	for (int i = 0; i < used; i++)
	{
		cout << toolHolder[i] << " | ";
	}
}

//Destructor
GChar::~GChar()
{
	cout << "Destructor called for " << this->name << " @ this memory location " << this << endl;
	delete[] toolHolder;
}

//Insert
void GChar::insert(const string& toolName)
{
	char choice;
	if (used == capacity)
	{
		cout << "The tool holder is full, Cannot add any additional tools" << endl;
		cout << "Current Capacity: " << capacity << endl;

		cout << "Would you like to expand the tool holder? If no, the item will be lost (Y/N):"; cin >> choice;
		
		if (choice == 'y' || choice == 'Y') {
			cout << "Expanding Toolbox..." << endl;

			string* tempTools = new string[used];				// create temporary array
			copy(toolHolder, toolHolder + used, tempTools);		// copy data into temporary storage
			delete[] toolHolder;								// Delete old storage
			capacity = used * 2;
			toolHolder = new string[capacity];
			copy(tempTools, tempTools + used, toolHolder);
			delete[] tempTools;

			cout << "Toolbox Expanded..." << endl;
			cout << "Updated Capacity: " << capacity << endl;
			cout << "Item Added to " << name << ", here is the contents of our toolHolder" << endl;
			toolHolder[used] = toolName;
			used++;
			for (int i = 0; i < used; i++)
			{
				cout << toolHolder[i] << " | ";
			}
			cout << endl;
		}
		else {
			cout << "Item lost" << endl;
		}
	}
	else
	{
		cout << "Item Added to " << name << ", here is the contents of our toolHolder" << endl;
		toolHolder[used] = toolName;
		used++;
		for (int i = 0; i < used; i++)
		{
			cout << toolHolder[i] << " | ";
		}
		cout << endl;
	}
}

int main()
{
	GChar gc1;
	gc1.insert("potion");
	gc1.insert("crossbow");
	gc1.insert("candle");
	gc1.insert("cloak");
	gc1.insert("sword");
	gc1.insert("book of spells");
	GChar gc2("Bob", 5);
	GChar gc3 = gc1;
	system("pause");
	return 0;
}

