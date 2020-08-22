#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int PLAYERS = 10;

struct player{					
	string name;
	string team;
	int GP;
	int runs;
	int hits;
	int doubles;		// 2B
	int triples;		// 3B
	int homeruns;		// HR
	int RBI;
	double avg;
};

void readData(ifstream& inFile, player players[PLAYERS]);
void menu(player players[PLAYERS]);

void printAll(player players[PLAYERS]);
void printPlayer(player players[PLAYERS]);
void printTeam(player players[PLAYERS]);
void changeStats(player players[PLAYERS]);

void readStats(int x, player players[PLAYERS]);

void outputFile(ofstream& outFile, player players[PLAYERS]);

int main() {
	player players[PLAYERS];
	ifstream inFile;
	ofstream outFile;
	inFile.open("stats.txt");
	if (!inFile) {
		cout << "Error\n";
		exit(0);
	}

	readData(inFile, players);
	
	menu(players);

	outputFile(outFile, players);

	system("pause");
	return 0;
}

void menu(player players[PLAYERS]) {
	int choice;
	while (true) {
		cout << "******************************************\nEnter the number of your choice:\n";
		cout << "1. Print out all players and statistics\n2. Print out statistics for a player\n"
			"3. Print out data for a team\n4. Update data for a specific player\nEnter any other number to exit\n";
		cout << "Choice: "; cin >> choice; cout << "\n******************************************\n\n";
		if (choice == 1) {
			printAll(players);
		}
		else if (choice == 2) {
			printPlayer (players);
		}
		else if (choice == 3) {
			printTeam(players);
		}
		else if (choice == 4) {
			changeStats(players);
		}
		else {
			break;
		}
	}
}

void printAll(player players[PLAYERS]) {
	for (int i = 0; i < PLAYERS; i++) {
		readStats(i, players);

	}
}

void printPlayer(player players[PLAYERS]) {
	int choice;
	cout << "Choose a player (input their number)\n1. Aaron Judge\n2. Brett Gardner\n3. Aaron Hicks\n4. Gary Sanchez\n5. Pete Alonso\n"
		"6. Wilson Ramos\n7. Amed Rosario\n8. Rafael Devers\n9. Christian Vazquez\n10. Mookie Betts\nEnter any other number to exit\n\n"; 
	cout << "Player: "; cin >> choice; cout << endl;
	switch(choice){
	case 1:
		 readStats(0, players);
		 break;
	case 2:
		readStats(1, players);
		break;
	case 3:
		readStats(2, players);
		break;
	case 4:
		readStats(3, players);
		break;
	case 5:
		readStats(4, players);
		break;
	case 6:
		readStats(5, players);
		break;
	case 7:
		readStats(6, players);
		break;
	case 8:
		readStats(7, players);
		break;
	case 9:
		readStats(8, players);
		break;
	case 10:
		readStats(9, players);
		break;
	default:
		break;
	}
}

void printTeam(player players[PLAYERS]) {
	string team;
	cout << "Choose a team (type team's whole name)\n1. New York Yankees\n2. New York Mets\n3. Boston Red Sox\nEnter 'Back' to exit\n";
	// Since I only used players from 3 teams I decided to just list the available teams out for the user
	cout << "Team: "; 
	cin.clear(); cin.ignore();
	getline(cin, team);
	
	for (int i = 0; i < PLAYERS; i++) {
			if (players[i].team == team) {
				readStats(i, players);
			}
		}
}

void changeStats(player players[PLAYERS]) {
	int choice1, choice2;
	cout << "Which player's stats would you like to update (enter the number of the player)\n1. Aaron Judge\n2. Brett Gardner\n3. Aaron Hicks\n4. Gary Sanchez\n5. Pete Alonso\n"
		"6. Wilson Ramos\n7. Amed Rosario\n8. Rafael Devers\n9. Christian Vazquez\n10. Mookie Betts\n\n";
	cout << "Player: "; cin >> choice1;
	cout << "Which stat would you like to update (enter the number of the stat)\n1. GP\n2. Runs\n3. Hits\n4. Doubles\n5. Triples"
		"\n6. Homeruns\n7. RBI\n8. Average\nEnter any other number to exit\n";
	cout << "Stat: "; cin >> choice2;
	choice1--;
			cout << "\n****" << players[choice1].name << "****\n";
			switch (choice2) {
			case 1:
				cout << "GP: "; cin >> players[choice1].GP;
				break;
			case 2:
				cout << "Runs: "; cin >> players[choice1].runs;
				break;
			case 3:
				cout << "Hits: "; cin >> players[choice1].hits;
				break;
			case 4:
				cout << "Doubles: "; cin >> players[choice1].doubles;
				break;
			case 5:
				cout << "Triples: "; cin >> players[choice1].triples;
				break;
			case 6:
				cout << "Homeruns: "; cin >> players[choice1].homeruns;
				break;
			case 7:
				cout << "Average: "; cin >> players[choice1].avg;
				break;
			default:
				break;
			}
}

void readData(ifstream& inFile, player players[PLAYERS]) {
	while (!inFile.eof()) {
		for (int i = 0; i < PLAYERS; i++) {
			getline(inFile, players[i].name, ',');
			getline(inFile, players[i].team, ':');
			inFile >> players[i].GP >> players[i].runs >> players[i].hits >> players[i].doubles >>
				players[i].triples >> players[i].homeruns >> players[i].RBI >> players[i].avg;
			inFile.ignore(1, '\n');
		}
	}
}

void readStats(int x, player players[PLAYERS]) {
	cout << "Name: " << players[x].name << "\nTeam: " << players[x].team << "\n********Stats********\nGames Played:\t" 
		<< players[x].GP << "\nRuns:\t\t" << players[x].runs << "\nHits:\t\t" << players[x].hits << "\nDoubles:\t" << players[x].doubles 
		<< "\nTriples:\t" << players[x].triples << "\nHomeruns\t" << players[x].homeruns << "\nRuns Batted In:\t" << players[x].RBI
		<< "\nAverage:\t" << players[x].avg << "\n\n";
}

void outputFile(ofstream& outFile, player players[PLAYERS]) {
	char choice;
	cout << "Would you like to store this data into a file?(Y/N): "; cin >> choice;

	if (choice == 'Y' || choice == 'y') {
		outFile.open("saveData.txt");
		if (!outFile) {
			cout << "Error]n";
			exit(0);
		}

		for (int i = 0; i < PLAYERS; i++) {
			outFile << players[i].name << ", " << players[i].team << ": GP: " << players[i].GP << ", Hits: " << players[i].hits
				<< ", Runs: " << players[i].runs << ", 2B: " << players[i].doubles << ", 3B: " << players[i].triples <<
				", HR: " << players[i].homeruns << ", RBI: " << players[i].RBI << ", Average: " << players[i].avg << "\n\n";
		}
		cout << "\nData successfully saved\n";
	}
	else {
		cout << "\nGoodbye\n";
	}
}

/* my data file
Aaron Judge,New York Yankees:		396 290 387 66 4 110 246 .273
Brett Gardner,New York Yankees:		1499 876 1355 230 68 124 524 .260
Aaron Hicks,New York Yankees:		654 324 506 89 10 82 276 .236
Gary Sanchez,New York Yankees:		372 226 343 61 1 105 262 .246
Pete Alonso,New York Mets:			161 103 155 30 2 53 120 .260
Wilson Ramos,New York Mets:			901 334 881 140 2 123 499 .275
Amed Rosario,New York Mets:			357 167 360 60 19 28 133 .270
Rafael Devers,Boston Red Sox:		335 222 372 92 4 63 211 .282
Christian Vazquez,Boston Red Sox:	429 169 360 72 4 33 152 .256
Mookie Betts,Boston Red Sox:		794 613 965 229 26 139 470 .301
*/
