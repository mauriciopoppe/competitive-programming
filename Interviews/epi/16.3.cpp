#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int m[9][9];

int test_value(int row, int col, int value) {
	for (int i = 0; i < 9; i += 1) {
		if (m[row][i] == value || m[i][col] == value) {
			return false;
		}
	}
	// todo: find value in a subsquare
	
	int row_start = row / 3;
	int col_start = col / 3;
	// cout << row_start << " " << col_start << endl;
	for (int i = 0; i < 3; i += 1) {
		for (int j = 0; j < 3; j += 1) {
			if (m[row_start * 3 + i][col_start * 3 + j] == value) {
				return false;
			}
		}
	}
	return true;
}

void print() {
	cout << "#####" << endl;
	for (int i = 0; i < 9; i += 1) {
		for (int j = 0; j < 9; j += 1) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void solve(int left, bool &solved) {
	if (!left) {
		solved = true;
		return;
	}

	int row = -1, col = -1;
	for (int i = 0; row == -1 && i < 9; i += 1) {
		for (int j = 0; col == -1 && j < 9; j += 1) {
			if (m[i][j] == -1) {
				row = i;
				col = j;
			}
		}
	}
	// print();
	// cout << row << " " << col << endl;
	// cin.ignore();
	for (int k = 1; k <= 9; k += 1) {
		if (!solved && test_value(row, col, k)) {
			m[row][col] = k;
			solve(left - 1, solved);
			if (!solved) {
				m[row][col] = -1;
			}
		}
	}
}

int main() {
	memset(m, -1, sizeof m);
	bool solved = false;
	m[0][0]=8;
	m[1][1]=9;
	m[2][2]=1;
	m[0][4]=5;
	m[0][8]=7;
	m[1][7]=6;
	m[2][6]=4;
	m[4][0]=3;
	m[3][3]=1;
	m[3][5]=9;
	m[4][4]=2;
	m[5][3]=7;
	m[5][5]=5;
	m[6][6]=2;
	m[7][7]=1;
	m[8][8]=3;
	m[4][8]=5;
	m[6][2]=4;
	m[7][1]=6;
	m[8][0]=5;
	m[8][4]=7;

	solve(9*9-21, solved);
	if (solved) {
		print();
	}
	return 0;
}