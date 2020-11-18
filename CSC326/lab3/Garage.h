#include "ArrayStack.cpp"
#include <cassert>



template<class type>
class garage {
private:
	ArrayStack<type> lane1;
	ArrayStack<type> lane2;
	ArrayStack<type> street;

	void moveCars(type& car);

public:
	garage() {};

	void arrival(type& car);
	void departure(type& car);
	bool search(const type& car);

};

template<class type>
void garage<type>::moveCars(type& car) {
	if (search(car)) {
		if (lane1.isHere(car)) {
			while (!lane1.isEmpty() && lane1.peek() != car) {
				type blockingCar = lane1.peek();

				blockingCar.move();
				cout << "Moving " << blockingCar.getPlate();
				if (!lane2.isFull()) {
					cout << " to lane 2 . . .\n";
					lane2.push(blockingCar);
				}
				else {
					cout << " to the street . . .\n";
					street.push(blockingCar);
				}
				lane1.pop();
			}
			type departingCar = lane1.peek();
			cout << departingCar.getPlate() << " is departing.  it was moved " << departingCar.getCount() << " times\n";
			lane1.pop();
			while (!street.isEmpty()) {
				type streetCar = street.peek();
				streetCar.move();
				if (!lane2.isFull()) {
					cout << "*Moving " << streetCar.getPlate() << " to lane 2*\n";
					lane2.push(streetCar);
				}
				else {
					cout << "*Moving " << streetCar.getPlate() << " to lane 1*\n";
					lane1.push(streetCar);
				}
				street.pop();
			}
		}
		else if (lane2.isHere(car)) {
			while (!lane2.isEmpty() && lane2.peek() != car) {
				type blockingCar = lane2.peek();

				blockingCar.move();
				cout << "Moving " << blockingCar.getPlate();
				if (!lane1.isFull()) {
					cout << " to lane 1 . . .\n";
					lane1.push(blockingCar);
				}
				else {
					cout << " to the street . . .\n";
					street.push(blockingCar);
				}
				lane2.pop();
			}
			type departingCar = lane2.peek();
			cout << departingCar.getPlate() << " is departing.  it was moved " << departingCar.getCount() << " times\n";
			lane2.pop();
			while (!street.isEmpty()) {
				type streetCar = street.peek();
				streetCar.move();
				if (!lane1.isFull()) {
					cout << "*Moving " << streetCar.getPlate() << " to lane 1*\n";
					lane1.push(streetCar);
				}
				else {
					cout << "*Moving " << streetCar.getPlate() << " to lane 2*\n";
					lane2.push(streetCar);
				}
				street.pop();
			}
		}
	}
}

template<class type>
void garage<type>::arrival(type& car) {
	if (!lane1.isFull()) {
		lane1.push(car);
		cout << "*" << car.getPlate() << " parked in lane 1*\n";

	}
	else if(!lane2.isFull()){
		lane2.push(car);
		cout << "*" << car.getPlate() << " parked in lane 2*\n";
	}
	else {
		cout << "*All lanes full, " << car.getPlate() << " departing*\n";
	}
}
template<class type>
void garage<type>::departure(type& car) {
	moveCars(car);
}

template<class type>
bool garage<type>::search(const type& car) {
	if (lane1.isHere(car) || lane2.isHere(car)) {
		return true;
	}
	cout << "This car is not here.  Ignoring . . .\n";
	return false;
}

