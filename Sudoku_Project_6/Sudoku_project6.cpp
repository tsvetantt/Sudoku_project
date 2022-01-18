#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;

int levelGenerator() {
	int level = 0;
	srand(time(NULL));
	level = rand() % 5 + 1;
	return level;
}

void readLevelsFromTxt(vector<vector<char>>& sudokoLevels, ifstream& sudokoLevelsFromTxt) {
	char temp;
	for (int i = 0; i < (18 * 5); i++) {
		sudokoLevels.push_back(vector<char>());
		for (int j = 0; j < 10; j++) {
			sudokoLevelsFromTxt.get(temp);
			sudokoLevels[i].push_back(temp);
		}
	}
	sudokoLevelsFromTxt.close();
}



int main() {
	int randomSudokoLevel = levelGenerator();

	cout << "Hello!" << endl;
	cout << "Enter the difficulty you want to play by pressing: " << endl;
	cout << " - 1 for easy mode!" << endl;
	cout << " - 2 for medium mode!" << endl;
	cout << " - 3 for hard mode!" << endl;
	int mode;
	cin >> mode;
	if (mode < 1 || mode > 3) {
		return 0;
	}

	int level;
	level = randomSudokoLevel;

	vector<vector<char>> sudokoLevels;
	vector<vector<char>> sudokoUnsolved;
	vector<vector<char>> sudokoUnsolvedCheck;
	vector<vector<char>> sudokoSolved;


	ifstream sudokoLevelsFromTxt;
	if (mode == 1) {
		sudokoLevelsFromTxt.open("EASY.txt", ios::in);
	}
	else if (mode == 2) {
		sudokoLevelsFromTxt.open("MEDIUM.txt", ios::in);
	}
	if (mode == 3) {
		sudokoLevelsFromTxt.open("HARD.txt", ios::in);
	}

	readLevelsFromTxt(sudokoLevels, sudokoLevelsFromTxt);
	
	return 0;
}