#include <iostream>
#include "tictactoe.h"

using namespace std;

char board[3][3];
int plays = 0;

void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '_';
		}
	}
}

void showBoard() {
	cout << "\t1\t2\t3\n";
	for (int i = 0; i < 3; i++) {
		cout << i + 1;
		for (int j = 0; j < 3; j++) {
			cout << "\t" << board[i][j];
			if (j == 2) cout << endl;
		}
	}
}

bool isValid(int prow, int pcolumn) {
	if (board[prow][pcolumn] != '_') {
		cout << "\nThis box is already taken\n" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool checkInput(int pvalue) {
	if (pvalue > 3 || pvalue < 1) {
		cout << "\nThis is an invalid input\n" << endl;
	}
	else {
		return true;
	}
}

void game() {
	while (!gameEnd()) {
		// This is a ternary conditional operator, syntax: (condition ? expression_if_true : expression_if_false);
		cout << "Player " << (plays % 2 == 0 ? "X" : "O") << " , it's your turn\n";
		showBoard();
		int row, column;
		do {
			do {
				cout << "Row of desired box: ";
				cin >> row;
			} while (!checkInput(row));

			do {
				cout << "Column of desired box: ";
				cin >> column;
			} while (!checkInput(column));
		} while (!isValid(row-1, column-1));
		
		board[row-1][column-1] = (plays % 2 == 0 ? 'X' : 'O');
		
		// Clear Screen
		#ifdef _WIN32
				system("cls");
		#else
				system("clear");
		#endif

		plays++;
	}
}

bool gameEnd() {
	// plays have to be greater than 5 so doesn't return true while boxes are '_'
	if (plays>4 &&
		// Row
		(board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
			board[1][0] == board[1][1] && board[1][0] == board[1][2] ||
			board[2][0] == board[2][1] && board[2][0] == board[2][2] ||

			// Column
			board[0][0] == board[1][0] && board[0][0] == board[2][0] ||
			board[0][1] == board[1][1] && board[0][1] == board[2][1] ||
			board[0][2] == board[1][2] && board[0][2] == board[2][2] ||

			// Diagonal
			board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
			board[2][0] == board[1][1] && board[2][0] == board[0][2])
		) {
		// Show board again as previously cleared screen, unlikely to be best way
		cout << "Game End\n";
		showBoard();
		cout << "Player " << (plays % 2 == 0 ? 'X' : 'O') << " wins!";

		return true;
	}

	if (plays == 9) {
		cout << "Game End\n";
		showBoard();
		cout << "Draw";
		return true;
	}

	return false;
}