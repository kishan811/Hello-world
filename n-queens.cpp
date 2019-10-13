#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool check(vector<vector<int>> &board, int row, int col, int n) {
	// top left
	for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--) {
		if(board[i][j] == 1)
			return false;
	}
	// left
	for(int j=col-1;j>=0;j--) {
		if(board[row][j] == 1)
			return false;
	}
	//down left
	for(int i=row+1, j=col-1;i<n && j>=0; i++, j--) {
		if(board[i][j] == 1)
			return false;
	}
	return true;
}

bool place_queens(vector<vector<int>> &board, int col, int n) {
	if(col == n) {
		return true;
	}
	int i=0;
	while(i < n) {
		board[i][col] = 1;
		if(check(board, i, col, n)) {
			int result = place_queens(board, col+1, n);
			if(result)
				return true;
		}
		board[i][col] = 0;
		i++;
	}

	return false;

}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> board;
	for(int i=0;i<n;i++) {
		vector<int> temp(n, 0);
		board.push_back(temp);
	}

	bool result = place_queens(board, 0, n);
	if(result) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		cout << "No solution is possible...";
	}

}