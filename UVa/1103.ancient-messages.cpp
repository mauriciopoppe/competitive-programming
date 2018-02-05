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

int hex_to_int(char c) {
	if (isdigit(c)) return c - '0';
	return 10 + c - 'a';
}

#define M 250
int m[M][M];
int visited[M][M];
int fig;
int row, col;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
map<int, int> mp;

int valid(int x, int y) {
	return x >= 0 && x < row && y >= 0 && y < col;
}

void print() {
	F(i, row) {
		F(j, col) {
			printf("%2d", m[i][j]);
		}
		NL;
	}
}

void dfs(int x, int y) {
	visited[x][y] = true;
	m[x][y] = fig;
	F(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && m[nx][ny] == -1) {
			dfs(nx, ny);
		}
	}
}

void check_figures() {
	fig = 0;
	F(i, row) {
		F(j, col) {
			if (m[i][j] == -1) {
				++fig;
				mp[fig] = 0;
				dfs(i, j);
			}
		}
	}
}

void check_cycle(int x, int y, set<int> &s) {
	visited[x][y] = true;
	F(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!valid(nx, ny)) {
			s.insert(-1);
		} else {
			if (m[nx][ny] > 0) {
				s.insert(m[nx][ny]);
			} else if (!visited[nx][ny]) {
				check_cycle(nx, ny, s);
			}
		}
	}
}

string solve() {
	check_figures();
	// print();

	set<int> s;
	check_cycle(0, 0, s);

	string sol = "";
	F(i, row) {
		F(j, col) {
			if (!visited[i][j]) {
				set<int> st;
				check_cycle(i, j, st);
				if (st.size() == 1) {
					mp[*st.begin()]++;
				}
			}
		}
	}

	TR(mp, it) {
		if (it->second == 1) sol += "A";
		if (it->second == 3) sol += "J";
		if (it->second == 5) sol += "D";
		if (it->second == 4) sol += "S";
		if (it->second == 0) sol += "W";
		if (it->second == 2) sol += "K";
	}
	sort(sol.begin(), sol.end());
	return sol;
}

void reset() {
	memset(visited, 0, sizeof visited);
	mp.clear();
}

int main() {
	int cas = 1;
	while (cin >> row >> col && row + col != 0) {
		string s;
		reset();
		F(i, row) {
			cin >> s;
			// cout << ">> " << s << endl;
			for (int j = 0; j < col; j += 1) {
				int h1 = hex_to_int(s[j]);
				m[i][4 * j + 3] = h1 & 1 ? -1 : 0;
				m[i][4 * j + 2] = h1 & 2 ? -1 : 0;
				m[i][4 * j + 1] = h1 & 4 ? -1 : 0;
				m[i][4 * j] = h1 & 8 ? -1 : 0;
			}
		}
		col *= 4;

		printf("Case %d: %s\n", cas++, solve().c_str());
	}
	return 0;
}