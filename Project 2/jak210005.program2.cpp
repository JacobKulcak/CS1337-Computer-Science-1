//Made using Microsoft Visual Studio 2022 Community on an ASUS Laptop running Windows 11//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void fileTest(string str)
{
	ofstream test;
	test.open("Findme.txt");
	test << str << endl;
	test.close();
}

void loadCipher(string* pStr) 
{
	ifstream input;
	input.open("cipher.txt");

	string line;
	string quote;

	while (!input.eof()) {
		input >> line;
		quote = quote + line + " ";
	}

	*pStr = quote;
	
	input.close();
}

void cleanText(string text, string* altOutput)
{
	string newQuote;

	for (int i = 0; i < text.length(); i++)
	{
		char letter = text[i];
		if (isalpha(letter)) {
			letter = toupper(letter);
			newQuote = newQuote + letter;
		}
	}
	*altOutput = newQuote;
}

char dataDisplay(string ltrs, int num) {
	cout << num << ":";

	for (int i = 0; i < (8 - num); i++)
	{
		cout << ".";
	}

	cout << ltrs.substr(0, num-1) << "[" << ltrs.substr(num-1, 1) 
		 << "]" << ltrs.substr(num, ltrs.length()-num);

	for (int i = 0; i < num; i++)
	{
		cout << ".";
	}
	
	cout << endl;

	return ltrs[num-1];
}

void process(string str, string* pStr)
{
	int sequence[] = { 7, 8, 7, 6, 5, 6, 5, 4, 3, 4, 3, 2, 1, 1, 2, 3, 4, 3, 4, 5, 6, 5,
	6, 7, 8, 7, 8, 8 , 7, 8, 7, 6, 5, 6, 5, 4, 3, 4, 3, 2, 1, 1, 2, 3, 4, 3, 4, 5, 6, 5,
	6, 7, 8, 7, 8, 8 , 7, 8, 7, 6, 5, 6, 5, 4, 4, 3, 3, 2, 1, 1, 2, 3, 4 };

	string cleanTxt, eight, newCipher;
	
	int count = 0;
	int count2 = 0;
	char chr;

	cleanText(str, &cleanTxt);
	
	for (char letter: cleanTxt) {
		eight = eight + letter;
		count++;

		if (count % 8 == 0) {
			chr = dataDisplay(eight, sequence[count2]);
			count2++;
			eight.clear();
			newCipher = newCipher + chr;
		}
	}
	*pStr = *pStr + newCipher;
}

void result(string msg)
{
	cout << "\nDecrypted Message: " << endl;
	cout << msg.substr(0, 28) << endl;
	cout << msg.substr(28, 24) << endl;
	cout << msg.substr(52, 21) << endl;
}

int main() 
{
	cout << "Jacob Kulcak \nCS 1337-502 \nProgram 1\n=========================" << endl;

	string testStr = "This is Only a Test";
	string cipher, newCipher;

	fileTest(testStr);

	loadCipher(&cipher);

	cout << "Cipher: " << cipher << "\n" << endl;

	process(cipher, &newCipher);

	result(newCipher);

	return 0;
}