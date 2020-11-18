#include <iostream>
#include <string>

using namespace std;

class car {
private: 
	string plate;
	int count;
public:
	car() {};
	car(string plate);
	string getPlate();
	int getCount();
	void move();

	friend bool operator== (const car& car1, const car& car2);
	friend bool operator!= (const car& car1, const car& car2);
};




car::car(string plate) {
	this->plate = plate;
	count = 0;
}

string car::getPlate() {
	return plate;
}
int car::getCount() {
	return count;
}

void car::move() {
	count++;
}

bool operator==(const car& car1, const car& car2) {
	return(car1.plate == car2.plate);
}
bool operator!=(const car& car1, const car& car2) {
	return(car1.plate != car2.plate);
}