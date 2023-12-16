//Made using Microsoft Visual Studio 2022 Community on an ASUS Laptop running Windows 11//
//This is the Game Engine portion of assignment 4//

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

string fileLocation = "C:\\Users\\jkulc\\Documents\\Save.txt";

struct grid
{
	int row;
	int col;
	char symbol;
};

struct creature
{
	string name;
	char symbol;
	int row;
	int col;
};

struct user
{
	string name;
	char symbol;
	string quest;
	string nonsense;
	int row;
	int col;
};

void myName()
{
	cout << "Jacob Kulcak" << endl;
	cout << "CS 1337 - 502" << endl;
	cout << "Program #4" << endl;
	cout << "28 October 2022" << endl;
	cout << "=======================" << endl;
}

void createUser(user *user) {
	string name;
	string quest;
	string nonsense;
	int question;
	char symbol;
	int row;
	int col;

	cout << "What is your name?" << endl;
	getline(cin, name);
	cin.ignore();

	cout << "What is your quest?" << endl;
	getline(cin, quest);
	cin.ignore();

	question = rand() % 3;
	switch (question){
	case 0:
		cout << "What is your favorite color?" << endl;
		getline(cin, nonsense);
		cin.ignore();
		break;
	case 1:
		cout << "What is the capital of Assyria?" << endl;
		getline(cin, nonsense);
		cin.ignore();
		break;
	case 2:
		cout << "What is the airspeed velocity of an unladen swallow?" << endl;
		getline(cin, nonsense);
		cin.ignore();
		break;
	}

	cout << "What is your symbol?" << endl;
	cin >> symbol;
	cin.ignore();

	cout << "What row are you in?" << endl;
	cin >> row;
	cin.ignore();

	cout << "What column are you in?" << endl;
	cin >> col;
	cin.ignore();

	user->name = name;
	user->quest = quest;
	user->nonsense = nonsense;
	user->symbol = symbol;
	user->col = col;
	user->row = row;
}

void createCreature(vector<creature>* crtlist) {
	string name;
	char symbol;
	int row;
	int col;

	cout << "What is its name?" << endl;
	getline(cin, name);
	cin.ignore();

	cout << "What is its symbol?" << endl;
	cin >> symbol;
	cin.ignore();

	cout << "What row is it in?" << endl;
	cin >> row;
	cin.ignore();

	cout << "What column is it in?" << endl;
	cin >> col;
	cin.ignore();

	struct creature* crt = new creature;
	crt->name = name;
	crt->symbol = symbol;
	crt->row = row;
	crt->col = col;
	crtlist->push_back(*crt);
}

void createTerrain(vector<grid>* terrain) {
	int row;
	string rowString;

	cout << "What row will this be?" << endl;
	cin >> row;
	cin.ignore();

	cout << "Please type 10 characters" << endl;
	getline(cin, rowString);
	cin.ignore();

	for (int i = 0; i < 10; i++) {
		struct grid* newGrid = new grid;
		newGrid->row = row;
		newGrid->col = i;
		newGrid->symbol = rowString.at(i);
		terrain->push_back(*newGrid);
	}
}

void saveFile(struct user user, vector<creature> creature, vector<grid> terrain) {
	ofstream output;
	
	output.open(fileLocation);
	output << user.name << "," << user.quest << "," << user.nonsense 
		   << "," << user.symbol << "," << user.row << "," << user.col << endl;
	
	output << creature.size() << endl;

	for (int i = 0; i < creature.size(); i++) {
		output << creature[i].name << ",";
		output << creature[i].symbol << ",";
		output << creature[i].row << ",";
		output << creature[i].col << endl;
	}
	
	output << terrain.size() << endl;

	for (int i = 0; i < terrain.size(); i++) {
		output << terrain[i].symbol << ",";
		output << terrain[i].row << ",";
		output << terrain[i].col << endl;
	}

	cout << "Data Saved" << endl;

	output.close();
}

int main()
{
	vector <grid> terrain;
	vector <creature> monsters;
	user student;

	srand(clock());
	string answer;
	int intAnswer;
	bool done = false;

	myName();

	while (!done)
	{
		cout << endl;
		cout << "1. Create User" << endl;
		cout << "2. Create Creature" << endl;
		cout << "3. Create a row of terrain" << endl;
		cout << "4. Save file" << endl;
		cout << "5. Quit" << endl;
		cout << "================================" << endl << endl;
		cout << "::>";

		cin >> answer;
		cin.ignore();

		if (isdigit(answer[0]))
		{
			intAnswer = stoi(answer);

			switch (intAnswer)
			{
			case 1:
				createUser(&student);
				break;
			case 2:
				createCreature(&monsters);
				break;
			case 3:
				createTerrain(&terrain);
				break;
			case 4:
				saveFile(student, monsters, terrain);
				break;
			case 5: 
				done = true;
				break;
			default:
				cout << "Silly Human!" << endl;
				break;
			}
		}
		else
		{
			cout << "HAL reports human error" << endl;
		}
		intAnswer = 0;
	}
	return 0;
}