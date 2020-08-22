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
	int numDays = 0;
	int sum = 0;
	int average;
	int count;

	while (inFile >> count) { // counts entries
		numDays++;
	}

	temperature = new int[numDays];

	inFile.close();
	inFile.open("temperatures.txt");
	if (!inFile) {
		exit(0);
	}

	cout << "Listing temperatures for " << numDays << " days...\n";
	for (int i = 0; i < numDays; i++) {
		inFile >> temperature[i];
		cout << "Day " << i + 1 << ":\t" << temperature[i] << endl;
		sum += temperature[i];
	}

	average = sum / numDays;
	cout << "Average temperature: " << average << endl;

	inFile.close();
	system("pause");
	return 0;
}

