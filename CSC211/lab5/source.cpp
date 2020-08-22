// Lab on recursion
#include <iostream>
#include <iomanip>
using namespace std;

int spacing(int A) {
	return (A * 2) + 2;
}
void pyramid(int A, int j) {
	j++;

	int space = spacing(A);

	for (int k = 0; k < j; k++) {
		space -= 2;
	}
	
	cout << setw(space);	

	for (int i = 0; i < j; i++) {
		cout << j << setw(4);
	}
	cout << endl;

	if (j != A) {
		pyramid(A, j);
	}
}



int main() {

	int num;

	cout << "What number do you want your pyramid to print to?\n"; cin >> num;

	pyramid(num, 0);
	

	system("pause");
	return 0;
}
