#pragma once
#include <iostream>
#include "Customer.h"

class Server {
private:
	bool busy;
	// pointer to existing customer
	Customer* customer;
public:
	Server() { busy = false; }
	Server(bool busy) { this->busy = busy; }


	bool isBusy() { return busy; }

	void setCustomer(Customer*, double);
	// function that shifts from not busy to busy vice versa
	void setBusy() { busy = true; }
	void setFree() { busy = false; }

	void serve();


	//void debug() { std::cout << "remaining: " << customer->getRemaining() << std::endl; }

	~Server() { customer = nullptr; }
};
// function that sets the customer at arrival time
void Server::setCustomer(Customer* customer,double servingTime) {
	this->customer = customer;
	customer->setWaiting(false);
	customer->setRemaining(servingTime);
}
// function that starts serving a customer
void Server::serve() {
	// Stop serving if there is no time remaining
	if (customer->getRemaining() == 1) {
		customer->serve();
		setFree();
	}
	else {
		customer->serve();
	}
}