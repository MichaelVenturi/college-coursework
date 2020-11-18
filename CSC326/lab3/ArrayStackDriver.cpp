#include <iostream>
#include <fstream>
#include <string>

#include "Car.h"
#include "Garage.h"

using namespace std;

int main() {

	ifstream inFile;
	inFile.open("input.txt");
	if (!inFile) {
		cout << "Error opening file\n";
		exit(0);
	}

	string data;
	garage<car> G;

	while (getline(inFile, data)) {
		char code = data[0];
		string plate = data.substr(2);
		car C(plate);
		cout << C.getPlate();

		switch (code) {
		case 'A':
			cout << " wants to arrive\n";
			G.arrival(C);
			break;
		case 'D':
			cout << " wants to depart\n";
			G.departure(C);
			break;
		default:
			cout << "Wrong input\n";
			break;
		}

	
	}

	inFile.close();
	return 0;
}