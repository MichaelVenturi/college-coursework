// Michael Venturi CSC211 Lab0
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Functions
bool leapYear(int year);							
int countYear(int year, int& dayValue);
int monthSwitch(int i, int year, int& dayValue);
int countMonth(int month, int year, int& dayValue);
string weekday(int dayValue);

int main() {

	 int day, month, year;
	 int dayValue;

	// READING DATES FROM FILE, WRITING ONTO ANOTHER FILE

	ifstream inFile;
	ofstream outFile;
	inFile.open("dates.txt");
	outFile.open("dateStats.txt");

	if (!inFile || !outFile) {
		cout << "ERROR"; exit(0);
	}

	cout << "*FROM FILE*\n\n";

	while (!inFile.eof()) {
		inFile >> month >> day >> year;
		
		 dayValue = 0;
		countYear(year, dayValue);
		countMonth(month, year, dayValue);
		dayValue += day;

		cout << weekday(dayValue) << ", " << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << year <<
			" has a day value of: " << dayValue << endl;
		cout << "\n*****************************************************\n\n";

		outFile << weekday(dayValue) << ", " << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << year <<
			" has a day value of: " << dayValue << endl;
	}
	inFile.close();
	outFile.close();

	// TAKING DATE FROM USER INPUT
	
	cout << "*FROM USER*\n\n";
	
	cout << "Input any date after 1900:\n\n";

	cout << "MONTH: "; cin >> month;
	cout << "DAY:   "; cin >> day;
	cout << "YEAR:  "; cin >> year;
	
	dayValue = 0;
	
	countYear(year, dayValue);
	countMonth(month, year, dayValue);
	dayValue += day;

	cout << "\n*****************************************************\n\n";

	cout << weekday(dayValue) << ", " << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << year <<
		" has a day value of: " << dayValue << "\n\n";

	// cout << "X " << setfill('0') << setw(2) << 3 << endl;   LEADING ZEROES ON MONTH/DAY
	// cout << "X " << setfill('0') << setw(2) << 23 << endl;

	system("pause");
	return 0;
}

/* 
Day-value: calculate all the days from 1900 to the year of the input date, then call a second 
function that calculates all the days up until the input month, and then just add the input day to that
*/

/*
A year is a leap year if:
-it is divisible by 4 but not 100
-it is divisible by 400
*/

bool leapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0) {
		return 1;}
	if (year % 400 == 0) {
		return 1;}
	else {	
		return 0;}
}

int countYear(int year, int& dayValue) {
	for (int i = 1900; i < year; i++) {
		if (leapYear(i) == 1) {
			dayValue += 366;}
		else {
			dayValue += 365;}
	}
	return dayValue;
}

int countMonth(int month, int year, int& dayValue) {
	for (int i = 0; i < month; i++) {
		monthSwitch(i, year, dayValue);
	}
	return dayValue;
}


int monthSwitch(int i, int year, int& dayValue) {
	switch (i) {
	case 0:
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		dayValue += 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		dayValue += 30;
		break;
	case 2:
		if (leapYear(year) == 1) {
			dayValue += 29;
			break;
		}
		else {
			dayValue += 28;
			break;
		}
	}
	return dayValue;
}

string weekday(int dayValue) {
	int D = dayValue % 7;
	switch (D) {
	case 0:
		return "Sunday";
		break;
	case 1:
		return "Monday";
		break;
	case 2:
		return "Tuesday";
		break;
	case 3:
		return "Wednesday";
		break;
	case 4:
		return "Thursday";
		break;
	case 5:
		return "Friday";
		break;
	case 6:
		return "Saturday";
		break;
	}
}


