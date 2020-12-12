#include <iostream>
#include<string>
#include <cstdlib>
#include <vector>
#include <time.h>

#include "ArrayQueue.h"
#include "Server.h"

using namespace std;

float bankSimulation(int numServers, double arrivTime, double servTime, double simTime);
bool doesArrive(double arrivTime);

int main() {
	// random arrivals each time
	srand(time(NULL));

	float test1 = bankSimulation(1, 5, 6, 100);
	cout << "Average wait time with 1 server: " << test1 << endl;
	float test2 = bankSimulation(2, 5, 6, 100);
	cout << "Average wait time with 2 servers: " << test2 << endl;
	float test3 = bankSimulation(3, 5, 6, 100);
	cout << "Average wait time with 3 servers: " << test3 << endl;

	return 0;
}

float bankSimulation(int numServers, double arrivTime, double servTime, double simTime) {

	ArrayQueue<Customer*> bankLine;

	// track customers and servers
	// use vectors since # of customers isn't certain
	vector<Customer*> customers;
	vector<Server*> servers;

	//cout << "Readying servers...\n";
	for (int i = 0; i < numServers; i++) {
		Server* x = new Server();
		servers.push_back(x);
	}

	double time = 0;
	//cout << "Beginning runtime\n";
	while (time < simTime) {
		time++;
		//cout << " Loop: " << time << endl;

		if (doesArrive(arrivTime)) {
			// new customer arrives at arrival time
			//cout << "Customer arrived\n";
			Customer* x = new Customer(time);
			customers.push_back(x);
			bankLine.enqueue(x);
		}
		
		for (auto& server : servers) {
			// if teller is free and a customer is on line
			if (!server->isBusy() && !bankLine.isEmpty()) {
				Customer* curCustomer = bankLine.peekFront();
				//cout << "Setting customer...\n";
				server->setCustomer(curCustomer, servTime);
				server->setBusy();
				bankLine.dequeue();
			}
			// if teller is not free
			else if (server->isBusy()){
				//cout << "Serving customer...\n";
				server->serve();
			}
			//else {
			//	cout << "empty server\n";
			//}
			
		}
		for (auto& customer : customers) {
			if (customer->isWaiting()) {
				//cout << "Customer is waiting\n";
				customer->stillWaiting();
			}
		}
	}
	//cout << "END LOOP\n";
	
	double totalWaitTime = 0;
	for (auto& customer : customers) {
		totalWaitTime += customer->getWait();
	}
	int totalCustomers = customers.size();
	float avgWaitTime = totalWaitTime / totalCustomers;

	return avgWaitTime;
}

bool doesArrive(double arrivTime) {
	float chance = 1 / float(arrivTime);
	float roll = rand() / float(RAND_MAX);
	return roll <= chance;
}


// debugging code
/*cout << "END LOOP\n";
	try {
		Customer* L = bankLine.peekFront();
		cout << L->getArrival() << endl;
		cout << L->getWait() << endl;
	}
	catch(PrecondViolatedExcep &e){
		cerr << e.what() << endl;
	}*/

