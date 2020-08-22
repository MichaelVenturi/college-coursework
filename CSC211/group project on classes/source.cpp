//John Bagdonas
// Serhiy Khalimon
// Danielle Ohana
// Jonathon Price
// Michael Venturi

#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

// ax + by = c
// y = (-a/b)x + (c/b);

const int QUAD = 4;

class lineType {
public:

	double getA();
	double getB();
	double getC();
	bool vertical();
	double slope();

	bool parallel(lineType);
	bool perpendicular(lineType);
	void intersect(lineType);
	bool isEqual(lineType);

	double pointX(lineType);
	double pointY(lineType);

	lineType();
	lineType(ifstream&);

private:

	double a;
	double b;
	double c;

};

void readData(lineType line1, lineType line2);

double distance(double x1, double x2, double y1, double y2);

bool isQuad(lineType Z[QUAD]);
bool isTrap(lineType Z[QUAD]);
bool isRight(lineType Z[QUAD]);
bool isSameLength(lineType Z[QUAD]);

void checkShape(lineType Z[QUAD]);

void printRectangle();
void printSquare();
void printParallelogram();
void printRhombus();
void printTrap();

int main() {
	
	// Part 1
	cout << "******************************\n";
	cout << "********|++PART ONE++|********\n";
	cout << "******************************\n\n";

	cout << "/----------------------------\\\n";
	cout << setw(19) << "Line 1\n";
	lineType line1;

	cout << setw(19) << "Line 2\n";
	lineType line2;

	readData(line1, line2);

	// Pauses the program after part 1 ends, since part 2 comes out all at once and pushes the results of part 1 out of sight
	cout << "\nPress any key to continue to part 2 . . .\n";
	_getch();

	// Part 2

	ifstream inFile;
	inFile.open("values.txt");
	if (!inFile) {
		cout << "Error opening file\n";
		exit(0);
	}

	cout << "\n*******************************\n";
	cout << "********|++PART TWO++|*********\n";
	cout << "*******************************\n\n";

	cout << "\n/----------------------------\\\n";
	cout << setw(20) << "set  one\n";
	cout << "\\----------------------------/\n";
	lineType setA[QUAD] = { inFile, inFile, inFile, inFile };

	checkShape(setA);

	cout << "\nPress any key to continue to set 2 . . .\n";
	_getch();

	cout << "\n/----------------------------\\\n";
	cout << setw(20) << "set  two\n";
	cout << "\\----------------------------/\n";

	lineType setB[QUAD] = { inFile, inFile, inFile, inFile };

	checkShape(setB);

	cout << "\nPress any key to continue to set 3 . . .\n";
	_getch();

	cout << "\n/----------------------------\\\n";
	cout << setw(21) << "set three\n";
	cout << "\\----------------------------/\n";

	lineType setC[QUAD] = { inFile, inFile, inFile, inFile };

	checkShape(setC);

	cout << "\nThis project will self-destruct when you press any key\n";
	_getch();

	return 0;

}

// Constructor for part 1: user input
lineType::lineType() {
	cout << "\\----------------------------/\n";
	cout << "\nEnter values for A, B, and C\n";
	cout << "A: "; cin >> a;
	cout << "B: "; cin >> b;
	cout << "C: "; cin >> c;
	cout << "\n/----------------------------\\\n";;
}
// Constructor for part 2: taken from file
lineType::lineType(ifstream& inFile) {
	inFile >> a >> b >> c;
}


double lineType::getA() {
	return a;
}
double lineType::getB() {
	return b;
}
double lineType::getC() {
	return c;
}

// check if line is vertical
bool lineType::vertical() {
	if (b == 0) {
		return true;
	}
	else {
		return false;
	}
}

// compute slope of line
double lineType::slope() {
	double slope;
	slope = -1 * (a / b);
	return slope;
}

// check if lines are parallel 
bool lineType::parallel(lineType Z) {
	if (vertical() == true && Z.vertical() == true) {
		return true;
	}
	else if (slope() == Z.slope()) {
		return true;
	}
	else {
		return false;
	}
}

// check if lines are perpendicular 
bool lineType::perpendicular(lineType Z) {
	if (vertical() == true && Z.a == 0 || Z.vertical() == true && a == 0) {
		return true;
	}
	else if (slope() * Z.slope() == -1) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if two lines intersect at point (x,y)
void lineType::intersect(lineType Z) {
	double x, y;								// coordinates (x,y)

	x = (c * Z.b - Z.c * b) / (a * Z.b - Z.a * b);
	y = (a * Z.c - Z.a * c) / (a * Z.b - Z.a * b);

	if (y == -0) {
		y = 0;
	}
	if (x == -0) {
		x = 0;
	}

	if (parallel(Z) == true) {
		cout << "+do not intersect\n";
	}
	else {
		cout << "+intersect at point:\n (" << x << ", " << y << ")" << endl;
	}
}

// Checks if two lines are equal
bool lineType::isEqual(lineType Z) {
	double factor;
	factor = a / Z.a;
	if (factor == b / Z.b && factor == c / Z.c) {
		return true;
	}
	else {
		return false;
	}
}

// returns all the part 1 functions in a nice fashion.  Keeps int main less cluttered
void readData(lineType line1, lineType line2) {
	cout << "These lines:\n";
	if (line1.parallel(line2) == 1) {
		cout << "+are parallel\n";
	}
	else {
		cout << "+are not parallel\n";
	}
	if (line1.perpendicular(line2) == 1) {
		cout << "+are perpendicular\n";
	}
	else {
		cout << "+are not perpendicular\n";
	}
	if (line1.isEqual(line2) == 1) {
		cout << "+are equivalent\n";
	}
	else {
		cout << "+are not equivalent\n";
	}
	line1.intersect(line2);
	if (line1.vertical() == 0) {
		cout << "+Line 1 has a slope of:\n " << line1.slope() << endl;
	}
	else {
		cout << "+Line 1's slope is undefined\n";
	}
	if (line2.vertical() == 0) {
		cout << "+Line 2 has a slope of:\n " << line2.slope() << endl;
	}
	else {
		cout << "+Line 2's slope is undefined\n";
	}
	cout << "\\----------------------------/\n";
}

// Checks if a set of four lines create a quadrilateral 
// PART 3 FUNCTION
bool isQuad(lineType Z[QUAD]) {

	if (Z[0].parallel(Z[1]) == 1 && Z[0].parallel(Z[2]) == 1 || Z[0].parallel(Z[2]) == 1 && Z[0].parallel(Z[3]) == 1 ||
		Z[0].parallel(Z[1]) == 1 && Z[0].parallel(Z[3]) == 1 || Z[1].parallel(Z[2]) == 1 && Z[1].parallel(Z[3]) == 1) {
		return false;
	}
	else if(Z[0].parallel(Z[1])==1 && Z[2].pointX(Z[0]) == Z[3].pointX(Z[0]) && Z[2].pointY(Z[0]) == Z[3].pointY(Z[0])
		|| Z[0].parallel(Z[1]) == 1 && Z[2].pointX(Z[1]) == Z[3].pointX(Z[1]) && Z[2].pointY(Z[1]) == Z[3].pointY(Z[1])){
		return false;
	}
	else if(Z[1].parallel(Z[2]) == 1 && Z[0].pointX(Z[1]) == Z[3].pointX(Z[1]) && Z[0].pointY(Z[1]) == Z[3].pointY(Z[1])
		|| Z[1].parallel(Z[2]) == 1 && Z[0].pointX(Z[2]) == Z[3].pointX(Z[2]) && Z[0].pointY(Z[2]) == Z[3].pointY(Z[2])) {
		return false;
	}
	else if (Z[2].parallel(Z[3]) == 1 && Z[0].pointX(Z[2]) == Z[1].pointX(Z[2]) && Z[0].pointY(Z[2]) == Z[1].pointY(Z[2])
		|| Z[2].parallel(Z[3]) == 1 && Z[0].pointX(Z[3]) == Z[1].pointX(Z[3]) && Z[0].pointY(Z[3]) == Z[1].pointY(Z[3])) {
		return false;
	}
	else if (Z[0].parallel(Z[2]) == 1 && Z[1].pointX(Z[0]) == Z[3].pointX(Z[0]) && Z[1].pointY(Z[0]) == Z[3].pointY(Z[0])
		|| Z[0].parallel(Z[2]) == 1 && Z[1].pointX(Z[2]) == Z[3].pointX(Z[2]) && Z[1].pointY(Z[2]) == Z[3].pointY(Z[2])) {
		return false;
	}
	else if(Z[0].parallel(Z[3]) == 1 && Z[2].pointX(Z[0]) == Z[1].pointX(Z[0]) && Z[2].pointY(Z[0]) == Z[1].pointY(Z[0])
		|| Z[0].parallel(Z[3]) == 1 && Z[2].pointX(Z[3]) == Z[1].pointX(Z[3]) && Z[2].pointY(Z[3]) == Z[1].pointY(Z[3])){
		return false;
	}
	else if (Z[1].parallel(Z[3]) == 1 && Z[2].pointX(Z[1]) == Z[0].pointX(Z[1]) && Z[2].pointY(Z[1]) == Z[0].pointY(Z[1])
		|| Z[1].parallel(Z[3]) == 1 && Z[2].pointX(Z[3]) == Z[0].pointX(Z[3]) && Z[2].pointY(Z[3]) == Z[0].pointY(Z[3])) {
		return false;
	}
	else {
		return true;
	}
}


// These return the X and Y coordinates for the point of intersection instead of outputting it as (x,y)
// Might not need the other function now that there are these, but no point in removing it.  It's already written out
double lineType::pointX(lineType Z) {
	double x;
	x = (c * Z.b - Z.c * b) / (a * Z.b - Z.a * b);
	return x;
}
double lineType::pointY(lineType Z) {
	double y;
	y = (a * Z.c - Z.a * c) / (a * Z.b - Z.a * b);
	return y;
}



double distance(double x1, double x2, double y1, double y2) {
	double distance;
	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return distance;
}

// He specified that in the lines he gave us, lines 1 and 2 are opposite eachother, and lines 3 and 4 are opposite eachother

bool isTrap(lineType Z[QUAD]) {
	if (Z[0].parallel(Z[1]) == 1 && Z[2].parallel(Z[3]) == 0 || Z[0].parallel(Z[1]) == 0 && Z[2].parallel(Z[3]) == 1) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if the lines are perpendicular/form right angles, meaning it is a square or rectangle
// Since this will only be called when isTrap is false, we only need to test if two lines are perpendicular once
// Since the shape has two sets of parallel lines, if any two lines form a right angle, then all of them do, and vice versa
bool isRight(lineType Z[QUAD]) {
	if (Z[0].perpendicular(Z[2]) == 1) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if all side lengths are equal or not.  If they are, it's a square or rhombus.  If they aren't, it is a rectangle or parallelogram
bool isSameLength(lineType Z[QUAD]) {
	if (distance(Z[0].pointX(Z[2]), Z[1].pointX(Z[2]), Z[0].pointY(Z[2]), Z[1].pointY(Z[2])) ==
		distance(Z[2].pointX(Z[0]), Z[3].pointX(Z[0]), Z[2].pointY(Z[0]), Z[3].pointY(Z[0]))
		) {
		return true;
	}
	else {
		return false;
	}
}

// Uses the previously defined functions to determine what shape the set of lines make
void checkShape(lineType Z[QUAD]) {
	cout << "\n";
	if (isQuad(Z) == 0) {
		cout << "+These lines do not form a quadrilateral\n";
	}
	else {
		if (isTrap(Z) == 1) {
			cout << "+These lines form a trapezoid\n";
			printTrap();
		}
		else {
			if (isRight(Z) == 1 && isSameLength(Z) == 0) {
				cout << "+These lines form a rectangle\n";
				printRectangle();
			}
			else if (isRight(Z) == 0 && isSameLength(Z) == 1) {
				cout << "+These lines form a rhombus\n";
				printRhombus();
			}
			else if (isRight(Z) == 1 && isSameLength(Z) == 1) {
				cout << "+These lines form a square\n";
				printSquare();
			}
			else if (isRight(Z) == 0 && isSameLength(Z) == 0) {
				cout << "+These lines form a parallelogram\n";
				printParallelogram();
			}
		}
	}
	cout << "\n";
}

void printRectangle() {
	// print out rectangle
	cout << "    ---------------------\n";
	cout << "    |                   |\n";
	cout << "    |                   |\n";
	cout << "    ---------------------\n";
} 

void printSquare() {
	// print out sqaure
	cout << "          ----------\n";
	cout << "          |        |\n"; 
	cout << "          |        |\n";
	cout << "          |        |\n";
	cout << "          ----------\n";
}

void printParallelogram() {
	// print parallelograms
	cout << "     -----------------------\n";
	cout << "    /                      /\n"; 
	cout << "   /                      /\n";
	cout << "  /                      /\n";
	cout << "  -----------------------\n";
}

void printRhombus() {

	// print rhombus
	cout << "              /\\      \n";
	cout << "             /  \\      \n";
	cout << "             \\  /         \n";
	cout << "              \\/           \n";
}

void printTrap() {

	// print trapezoid
	cout << "        -------------      \n";
	cout << "       /             \\      \n";
	cout << "      /               \\      \n";
	cout << "      -----------------       \n";
}
// Our function for part 3 is the “isQuad” function, which we integrated into part 2.  
// It does not move on to check what shape each set makes until it knows it is a quadrilateral first

