#pragma once


class Customer {
private:
	bool waiting;
	double arrivalTime, waitTime, remainingTime;
public:
	Customer() { }
	Customer(double arrivalTime);

	double getArrival() { return arrivalTime; }
	double getWait() { return waitTime; }
	double getRemaining() { return remainingTime; }
	bool isWaiting() { return waiting; }

	// Set when they begin being served
	void setRemaining(double remainingTime) { this->remainingTime = remainingTime; }
	void setWaiting(bool waiting) { this->waiting = waiting; }

	void stillWaiting() { waitTime++; }
	void serve() { remainingTime--; }

};

Customer::Customer(double arrivalTime) {
	waiting = true;
	this->arrivalTime = arrivalTime;
	waitTime = 0;
}