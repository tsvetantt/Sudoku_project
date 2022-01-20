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

void specificLevelSolved(vector<vector<char>>& sudokoLevels, vector<vector<char>>& sudokoSolved, int level) {
	int startOfLevel = (level - 1) * 18;
	for (int i = 0; i < 9; i++) {
		sudokoSolved.push_back(vector<char>());
		for (int j = 0; j < 10; j++) {
			sudokoSolved[i].push_back(sudokoLevels[startOfLevel][j]);
		}
		startOfLevel++;
	}
}

vector<vector<char>> specificLevelUnsolved(vector<vector<char>>& sudokoLevels, vector<vector<char>>& sudokoUnsolved, int level) {
	int startOfLevel = ((level - 1) * 18) + 9;
	for (int i = 0; i < 9; i++) {
		sudokoUnsolved.push_back(vector<char>());
		for (int j = 0; j < 10; j++) {
			sudokoUnsolved[i].push_back(sudokoLevels[startOfLevel][j]);
		}
		startOfLevel++;
	}
	return sudokoUnsolved;
}

bool checkIfSolutionIsSeenOneTimeInTheRow(vector<vector<char>>& sudokoSolved, vector<vector<char>>& sudokoUnsolved, int row, char solution) {
	char temp;
	for (int i = 0; i < 9; i++) {
		temp = sudokoUnsolved[row - 1][i];
		if (temp == solution) {
			return false;
			break;
		}
	}
	return true;
}

bool checkIfSolutionIsSeenOneTimeInTheColumn(vector<vector<char>>& sudokoSolved, vector<vector<char>>& sudokoUnsolved, int column, char solution) {
	char temp;
	for (int i = 0; i < 9; i++) {
		temp = sudokoUnsolved[i][column - 1];
		if (temp == solution) {
			return false;
			break;
		}
	}
	return true;
}

bool checkIfSolutionIsSeenInABox(vector<vector<char>>& sudokoUnsolved, int column, int row, char solution) {
	if ((row - 1) >= 0 && (row - 1) <= 2 && (column - 1) >= 0 && (column - 1) <= 2) {      // 1box
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
	else if ((row - 1) >= 0 && (row - 1) <= 2 && (column - 1) >= 3 && (column - 1) <= 5) {      // 2box
		for (int i = 0; i < 3; i++) {
			for (int j = 3; j < 6; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
	else if ((row - 1) >= 0 && (row - 1) <= 2 && (column - 1) >= 6 && (column - 1) <= 8) {      // 3box
		for (int i = 0; i < 3; i++) {
			for (int j = 6; j < 9; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
	else if ((row - 1) >= 3 && (row - 1) <= 5 && (column - 1) >= 0 && (column - 1) <= 2) {      // 4box
		for (int i = 3; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
	else if ((row - 1) >= 3 && (row - 1) <= 5 && (column - 1) >= 3 && (column - 1) <= 5) {      // 5box
		for (int i = 3; i < 6; i++) {
			for (int j = 3; j < 6; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
	else if ((row - 1) >= 3 && (row - 1) <= 5 && (column - 1) >= 6 && (column - 1) <= 8) {      // 6box
		for (int i = 3; i < 6; i++) {
			for (int j = 6; j < 9; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
	else if ((row - 1) >= 6 && (row - 1) <= 8 && (column - 1) >= 0 && (column - 1) <= 2) {      // 7box
		for (int i = 6; i < 9; i++) {
			for (int j = 0; j < 3; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
	else if ((row - 1) >= 6 && (row - 1) <= 8 && (column - 1) >= 3 && (column - 1) <= 5) {      // 8box
		for (int i = 6; i < 9; i++) {
			for (int j = 3; j < 6; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
	else if ((row - 1) >= 6 && (row - 1) <= 8 && (column - 1) >= 6 && (column - 1) <= 8) {      // 9box
		for (int i = 6; i < 9; i++) {
			for (int j = 6; j < 9; j++) {
				if (sudokoUnsolved[i][j] == solution) {
					return false;
					break;
				}
			}
		}
		return true;
	}
}

bool checkingAnswers(vector<vector<char>>& sudokoUnsolved, vector<vector<char>>& sudokoSolved) {
	int check = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudokoUnsolved[i][j] == sudokoSolved[i][j]) {
				check++;
			}
			else {
				return false;
				break;
			}
		}
	}
	if (check == 81) {
		return true;
	}
}

int solvingSudoko(vector<vector<char>>& sudokoSolved, vector<vector<char>>& sudokoUnsolved, vector<vector<char>>& sudokoUnsolvedCheck) {

	if (checkingAnswers(sudokoUnsolved, sudokoSolved)) {
		cout << "C O N G R A T U L A T I O N S ! ! !" << endl << "Y O U  W O N  T H E  G A M E";
		return 0;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudokoUnsolved[i][j] << " ";
		}
		cout << endl;
	}

	int check = 0;
	int row = 0;
	int column = 0;
	char solution;
	cout << endl;
	cout << "Enter the coordinates of the cell you want to edit!" << endl;
	cin >> row;
	cin >> column;
	cout << "Please, enter yor solution or type '0' to delete your solution!" << endl;
	cin >> solution;
	if (column < 1 || column > 9 || row < 1 || row > 9) {
		cout << "Invalid coordinates!!" << endl;
		cout << "Try again!" << endl;
		cout << endl;
		return solvingSudoko(sudokoSolved, sudokoUnsolved, sudokoUnsolvedCheck);
	}
	//cout << row << column << solution;
	if (solution == '0') {
		if (sudokoUnsolvedCheck[row - 1][column - 1] == '-' && sudokoUnsolved[row - 1][column - 1] != '-') {
			sudokoUnsolved[row - 1][column - 1] = '-';
		}
		else if (sudokoUnsolvedCheck[row - 1][column - 1] == '-' && sudokoUnsolved[row - 1][column - 1] == '-') {
			cout << "There is no solution to be deleted!" << endl;
			cout << endl;
			return solvingSudoko(sudokoSolved, sudokoUnsolved, sudokoUnsolvedCheck);
		}
		else {
			cout << "You can not delete this number, because it is not your solution!" << endl;
			cout << endl;
		}

	}
	else {
		if (sudokoUnsolvedCheck[row - 1][column - 1] != '-') {
			cout << "You can not change this number, because it is not your solution!" << endl;
			cout << endl;
			return solvingSudoko(sudokoSolved, sudokoUnsolved, sudokoUnsolvedCheck);
		}
		else {
			if (!checkIfSolutionIsSeenOneTimeInTheRow(sudokoSolved, sudokoUnsolved, row, solution)) {
				cout << "There is already " << solution << " in that row!" << endl;
				check++;
			}
			if (!checkIfSolutionIsSeenOneTimeInTheColumn(sudokoSolved, sudokoUnsolved, column, solution)) {
				cout << "There is already " << solution << " in that column!" << endl;
				check++;
			}
			if (!checkIfSolutionIsSeenInABox(sudokoUnsolved, column, row, solution)) {
				cout << "There is already " << solution << " in the box!" << endl;
				check++;
			}
			if (check == 0) {
				sudokoUnsolved[row - 1][column - 1] = solution;
			}
		}
	}
	cout << endl;
	return solvingSudoko(sudokoSolved, sudokoUnsolved, sudokoUnsolvedCheck);
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
	specificLevelSolved(sudokoLevels, sudokoSolved, level);
	specificLevelUnsolved(sudokoLevels, sudokoUnsolved, level);
	specificLevelUnsolved(sudokoLevels, sudokoUnsolvedCheck, level);

	solvingSudoko(sudokoSolved, sudokoUnsolved, sudokoUnsolvedCheck);

	return 0;
}