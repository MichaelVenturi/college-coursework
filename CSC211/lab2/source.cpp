#include <iostream>
#include <string>
using namespace std;

class secretType {
public:
	void print();
	string getName();
	int getAge();
	double getWeight();
	double getHeight();
	string weightStatus();
	secretType();
private:
	string name;
	int age;
	double weight;
	double height;
};

int main() {
	secretType p1;

	p1.print();

	cout << "Weight status: " << p1.weightStatus() << endl;

	system("pause");
	return 0;
}

void secretType::print() {
	cout << "\n************************\n";
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Weight: " << weight << endl;
	cout << "Height: " << height << endl;
	cout << "************************\n\n"; 
}
string secretType::getName() {
	return name;
}
int secretType::getAge() {
	return age;
}
double secretType::getWeight() {
	return weight;
}
double secretType::getHeight() {
	return height;
}
string secretType::weightStatus() {
	double BMI;
	BMI = weight / (pow(height, 2));
	string weightStatus;
	if (BMI < 18.5) {
		weightStatus = "Underweight";
	}
	else if (BMI >= 18.5 && BMI <= 24.9) {
		weightStatus = "Normal";
	}
	else if (BMI >= 25 && BMI <= 29.9) {
		weightStatus = "Overweight";
	}
	else if (BMI >= 30) {
		weightStatus = "Obese";
	}
	return weightStatus;
}
secretType::secretType() {
	cout << "Enter name: "; getline(cin, name);
	cout << "Enter age: "; cin >> age;
	cout << "Enter weight(in kg): "; cin >> weight;
	cout << "Enter height(in meters): "; cin >> height;
}

