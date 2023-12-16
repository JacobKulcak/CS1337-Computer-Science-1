//Made using Microsoft Visual Studio 2022 Community on an ASUS Laptop running Windows 11//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <Windows.h>
#include <cstdlib>

using namespace std;

//for bonus
enum notes{Cn, Cs, Db, Dn, Ds, Eb, Fn, Fs, Gb, Gn, Gs, Ab, An, As, Bb, Bn};
const int notes[17] = { 16.35, 17.32, 17.32, 18.35, 19.45, 19.45, 20.60,21.83, 23.12,
						23.12, 24.50, 25.96, 25.96, 27.50, 29.14, 29.14, 30.87 };
//store frequencies of every note, then they can be multiplied by the octave

void myName() {
	cout << "Jacob Kulcak" << endl;
	cout << "CS 1337 - 502" << endl;
	cout << "Program #3" << endl;
	cout << "13 October 2022" << endl;
	cout << "=======================" << endl;
}

struct Key {
	int octave;
	char letter;
	char symbol;
	double frequency;
	double wavelength;
};

struct Note {
	int octave;
	char letter;
	char symbol;
	int duration;
};

struct Key* makeKey(int octave, char keyLetter, char keySymbol, double freq, double wave) {
	struct Key* result = nullptr;

	result = new Key;
	result->octave = octave;
	result->letter = keyLetter;
	result->symbol = keySymbol;
	result->frequency = freq;
	result->wavelength = wave;

	return result;
}

struct Note* makeNote(char letter, int octave, char symbol, int duration) {
	struct Note* result = nullptr;

	result = new Note;
	result->octave = octave;
	result->letter = letter;
	result->symbol = symbol;
	result->duration = duration;

	return result;
}

void showKeyS(Key myKey) {
	cout << setw(1) << myKey.letter << " ";
	cout << setw(1) << myKey.symbol << " ";
	cout << setw(1) << myKey.octave << " ";
	cout << setw(7) << fixed << setprecision(4) << myKey.frequency << "*";
	cout << setw(7) << fixed << setprecision(4) << myKey.wavelength << "=";
	cout << myKey.frequency * myKey.wavelength;
	cout << endl;
}

void showNoteS(Note myNote) {
	cout << setw(1) << myNote.letter << " ";
	cout << setw(1) << myNote.octave << " ";
	cout << setw(1) << myNote.symbol << " ";
	cout << setw(1) << myNote.duration << " ";
	cout << endl;
}

void showKeyV(vector <Key> keyVec) {
	for (int i = 0; i < keyVec.size(); i++) {
		showKeyS(keyVec.at(i));
	}
}

void showNoteV(vector <Note> noteVec) {
	for (int i = 0; i < noteVec.size(); i++) {
		showNoteS(noteVec.at(i));
	}
}

int fetchIndex(Note target, vector<Key> keyVec) {
	int result = -1;
	for (int i = 0; i < keyVec.size(); i++) {
		if (target.letter == keyVec[i].letter) {
			if (target.octave == keyVec[i].octave) {
				if (target.symbol == keyVec[i].symbol) {
					result = i;
				}
			}
		}
	}
	return result;
}

void loadKey(vector <Key>* keys){
	ifstream keyFile("keys.txt");
	string token;

	struct Key* newKey;

	char keyLetter = '\0';
	char keySymbol = '\0';
	int octave = 0;
	double freq = 0.0;
	double wavelength = 0.0;

	while (!keyFile.eof()){
		getline(keyFile, token, ',');
		octave = stoi(token);
		getline(keyFile, token, ',');
		keyLetter = token[0];
		getline(keyFile, token, ',');
		keySymbol = token[0];
		getline(keyFile, token, ',');
		freq = stod(token);
		getline(keyFile, token, '\n');
		wavelength = stod(token);

		newKey = makeKey(octave, keyLetter, keySymbol, freq, wavelength);

		keys->push_back(*newKey);

	}
	keyFile.close();
}

void getFilename(string* pStr) {
	string name;
	cout << "Enter a Filename: ";
	cin >> name;
	*pStr = name;
}

void loadTune(string filename, vector<Note>* tune) {
	ifstream tuneFile(filename);
	char letter = '\0';
	int octave = 0;
	char symbol = '\0';
	char comma = '\0';
	int duration = 0;
	string token;
	Note* newNote = nullptr;

	while (!tuneFile.eof()) {
		tuneFile >> letter;
		tuneFile >> octave;
		tuneFile >> symbol;
		tuneFile >> comma;
		tuneFile >> duration;
		newNote = makeNote(letter, octave, symbol, duration);
		tune->push_back(*newNote);
	}

	tuneFile.close();
}

void drawNote(int minOctave, int maxOctave, int index, int duration) {
	int startpos = minOctave * 17;
	int stoppos = (maxOctave + 1) * 17;
	int loop = 0;

	for (loop = startpos; loop < index; loop++) {
		cout << ".";
	}

	switch (duration) {
	case 125: 
		cout << "|"; 
		break;
	case 250:
		cout << "+";
		break;
	case 500:
		cout << "o";
		break;
	case 750:
		cout << "O";
		break;
	case 1000:
		cout << "$";
		break;
	default:
		cout << "-";
		break;
	}

	for (loop = index; loop < stoppos; loop++) {
		cout << ".";
	}

	cout << endl;
}

void drawTune(vector <Note> noteVec, vector <Key> keyVec) {
	int max = noteVec.size();
	int minOctave = -1;
	int maxOctave = -1;

	minOctave = noteVec[0].octave;
	for (int i = 1; i < max; i++) {
		if (noteVec[i].octave < minOctave) {
			minOctave = noteVec[i].octave;
		}
	}

	maxOctave = noteVec[0].octave;
	for (int i = 1; i < max; i++) {
		if (noteVec[i].octave > maxOctave) {
			maxOctave = noteVec[i].octave;
		}
	}

	for (int i = 0; i < max; i++) {
		Note temp = noteVec[i];
		int index = fetchIndex(temp, keyVec);
		int duration = temp.duration;
		drawNote(minOctave, maxOctave, index, duration);
	}
}

/*void playTune(vector <Note> tuneVec) {
	float freq = 0;
	char symbol = '\0';
	string note = "An";

	for (int i = 0; i < tuneVec.size(); i++) {

		if (tuneVec[i].symbol == '#') {
			symbol = 's';
		}
		else if (tuneVec[i].symbol == 'b') {
			symbol = 'b';
		}
		else {
			symbol = 'n';
		}

		note = tuneVec[i].letter + symbol;

		Beep((note * (2 ^ tuneVec[i].octave)), tuneVec[i].duration);
	}
}*/

void menu() {
	bool exit = false;
	char input;
	vector<Key> keyVec;
	vector<Note> noteVec;
	string filename;

	while (!exit) {
		cout << "1. Load Key File" << endl;
		cout << "2. Show Loaded Keys" << endl;
		cout << "3. Set Tune Filename" << endl;
		cout << "4. Load Tune File" << endl;
		cout << "5. Show Tune File" << endl;
		cout << "6. Draw Tune File" << endl;
		cout << "7. Bonus: Play Tune File" << endl;
		cout << "8. Exit" << endl;
		cout << "============================" << endl;
		cout << "::> ";

		cin.clear();
		cin >> input;

		switch (input) {
		case '1':
			loadKey(&keyVec);
			break;
		case'2':
			showKeyV(keyVec);
			break;
		case '3':
			getFilename(&filename);
			break;
		case '4':
			loadTune(filename, &noteVec);
			break;
		case '5':
			showNoteV(noteVec);
			break;
		case '6':
			drawTune(noteVec, keyVec);
			break;
		case '7':
			cout << "Try this again in the next update";
			//playTune(noteVec);
			break;
		case '8':
			exit = true;
			break;
		}
	}
}

int main(){
	myName();
	menu();

	return 1;
}