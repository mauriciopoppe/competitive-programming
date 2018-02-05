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

#define M 100
int m[M][M];
int visited[M][M];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool inside_matrix(int x, int y) {
	return x >= 0 && x < M &&
		y >= 0 && y < M;
}

bool can_move(int x, int y) {
	return inside_matrix(x, y) &&
		m[x][y] == false &&
		visited[x][y] = false;
}

bool find(pair<int,int> start, pair<int, int> end) {
	queue<pair<int,int> > q;
	visited[start.first][start.second] = true;
	q.push(start);

	int solved = false;
	while (!q.empty()) {
		pair<int,int> top = q.front();

		if (top.first == end.first && top.second == end.second) {
			solved = true;
			break;
		}

		q.pop();
		for (int i = 0; i < 4; i += 1) {
			int newX = top.first + dx[i];
			int newY = top.second + dy[i];
			if (can_move(newX, newY)) {
				visited[newX][newY] = true;
				q.push( pair<int, int>(newX, newY) );
			}
		}
	}
	return solved;
}

int main() {
	memset(m, 0, sizeof M);
	memset(visited, 0, sizeof visited);
	
	return 0;
}