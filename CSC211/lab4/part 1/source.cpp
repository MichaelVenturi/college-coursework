#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream inFile;
	inFile.open("temperatures.txt");
	if (!inFile) {
		exit(0);
	}

	int* temperature;
	int numDays;
	int sum = 0;
	int average;

	cin >> numDays;

	temperature = new int[numDays];

	for (int i = 0; i < numDays; i++) {
		inFile >> temperature[i];
		cout << temperature[i] << endl;
		sum += temperature[i];
	}

	average = sum / numDays;
	cout << "Average: " << average << endl;

	system("pause");
	return 0;
}

/* Fixed code for question 2 

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char*  codeIt(char* s)
{
	int i;
	int len = strlen(s);
	char* result;
	result = new char[len];
	for (i = 0; i < len; i++) 
		result[i] = s[i] + 2;
		result[i] = '\0';
	return result;
}
int main()
{
	char* str;
	char* codedStr;

	int strLen;
	int len;
	char ch;

	int i;

	cout << "Enter the size of the string: ";
	cin >> strLen;
	cout << endl;

	cin.get(ch);

	str = new char[strLen + 1];
	//codedStr = new char[strLen + 1];

	cout << "Enter a string of length at most "
		<< strLen << ": ";
	cin.get(str, strLen + 1);
	cout << endl;

	codedStr = codeIt(str);

	cout << codedStr << endl;

	system("pause");
	return 0;
}

*/

