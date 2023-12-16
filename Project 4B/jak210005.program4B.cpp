//Made using Microsoft Visual Studio 2022 Community on an ASUS Laptop running Windows 11//
//This is the World Builder portion of assignment 4//

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

void myName() {
	cout << "Jacob Kulcak" << endl;
	cout << "CS 1337 - 502" << endl;
	cout << "Program #4" << endl;
	cout << "28 October 2022" << endl;
	cout << "=======================" << endl;
}

void loadFile(user* player, vector<creature>* monsters, vector<grid>* terrain) {
	ifstream input(fileLocation);
	string token;
	int monsterSize;
	int terrainSize;

	getline(input, token, ',');
	player->name = token;
	getline(input, token, ',');
	player->quest = token;
	getline(input, token, ',');
	player->nonsense = token;
	getline(input, token, ',');
	player->symbol = token[0];
	getline(input, token, ',');
	player->row = stoi(token);
	getline(input, token, '\n');
	player->col = stoi(token);

	getline(input, token, '\n');
	monsterSize = stoi(token);

	for (int i = 0; i < monsterSize; i++) {
		creature* crt = new creature;

		getline(input, token, ',');
		crt->name = token;
		getline(input, token, ',');
		crt->symbol = token[0];
		getline(input, token, ',');
		crt->row = stoi(token);
		getline(input, token, '\n');
		crt->col = stoi(token);

		monsters->push_back(*crt);
	}

	getline(input, token, '\n');
	terrainSize = stoi(token);

	for (int i = 0; i < terrainSize; i++) {
		grid* grd = new grid;

		getline(input, token, ',');
		grd->symbol = token[0];
		getline(input, token, ',');
		grd->row = stoi(token);
		getline(input, token, '\n');
		grd->col = stoi(token);

		terrain->push_back(*grd);
	}
}

void displayTerrain(user student, vector<creature> monsters, vector<grid> terrain)
{
	char map[10][10];
	int row;
	int col;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			map[row][col] = '.';
		}
	}

	int terrainMax;
	int terrainLoop;
	grid gtemp;
	terrainMax = terrain.size();
	for (terrainLoop = 0; terrainLoop < terrainMax; terrainLoop++)
	{
		gtemp = terrain[terrainLoop];
		map[gtemp.row][gtemp.col] = gtemp.symbol;
	}

	int monsterMax;
	int monsterLoop;
	monsterMax = monsters.size();

	for (monsterLoop = 0; monsterLoop < monsterMax; monsterLoop++)
	{
		creature temp = monsters[monsterLoop];
		map[temp.row][temp.col] = temp.symbol;
	}

	map[student.row][student.col] = student.symbol;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			cout << setw(2) << map[row][col];
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < monsters.size(); i++) {
		cout << monsters[i].symbol << ':' << monsters[i].name << endl;
	}

	cout << endl;

	cout << student.symbol << ':' << student.name << endl;
	cout << student.quest << endl;
	cout << student.nonsense << endl;
}

int main() {
	struct user user;
	vector<creature> monsters;
	vector<grid> terrain;
	
	myName();
	loadFile(&user, &monsters, &terrain);
	displayTerrain(user, monsters, terrain);

	return 0;
}