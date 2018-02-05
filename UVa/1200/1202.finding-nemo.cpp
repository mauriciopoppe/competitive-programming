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

#define M 205

int v[M][M];
int h[M][M];
int door_v[M][M];
int door_h[M][M];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int wall_x(int x, int y, int diff, int m[M][M]) {
	int wall = x;
	if (diff > 0) {
		wall += 1;
	}
	return m[wall][y];
}

int wall_y(int x, int y, int diff, int m[M][M]) {
	int wall = y;
	if (diff > 0) {
		wall += 1;
	}
	return m[x][wall];
}

int move(int x, int y, int diff_x, int diff_y) {
	if (diff_x != 0) {
		if (!wall_x(x, y, diff_x, v)) {
			return wall_x(x, y, diff_x, door_v);
		}
	} else {
		if (!wall_y(x, y, diff_y, h)) {
			return wall_y(x, y, diff_y, door_h);
		}
	}
	return -1;
}

int sssp(pair<int, int> start, pair<int, int> nemo) {
	map<pair<int, int>, int> d;
	set<pair<int, pair<int, int> > > q;
	d[start] = 0;
	q.insert({ 0, start });

	while (!q.empty()) {
		pair<int, int> top = q.begin()->second;
		q.erase(q.begin());
		int top_dist = d[top];

		// NL;
		// printf("d = %d, v = %d %d\n", q.begin()->first, top.first, top.second);

		if (top == nemo) {
			return d[top];
		}

		for (int i = 0; i < 4; i += 1) {
			int nx = top.first + dx[i];
			int ny = top.second + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < M) {
				// printf("attempt = %d %d\n", nx, ny);
				int weight = move(top.first, top.second, dx[i], dy[i]);
				// printf("w = %d\n", weight);
				if (weight >= 0) {
					pair<int, int> to = {nx, ny};
					if (!d.count(to) || d[to] > top_dist + weight) {
						q.erase({ d[to], to });
						d[to] = top_dist + weight;
						q.insert({ d[to], to});
					}
				}
			}
		}
	}

	return -1;
}

int main() {
	int walls, doors;
	while (cin >> walls >> doors) {
		if (walls < 0 && doors < 0) {
			break;
		}

		for (int i = 0; i < M; i += 1) {
			for (int j = 0; j < M; j += 1) {
				v[i][j] = h[i][j] = door_v[i][j] = door_h[i][j] = 0;
			}
		}

		int x, y, dir, len;
		for (int i = 0; i < walls; i += 1) {
			cin >> x >> y >> dir >> len;
			for (int j = 0; j < len; j += 1) {
				if (dir == 1) {
					// y
					v[x][y + j] = 1;
				} else {
					// x
					h[x + j][y] = 1;
				}
			}
		}

		len = 1;
		for (int i = 0; i < doors; i += 1) {
			cin >> x >> y >> dir;
			for (int j = 0; j < len; j += 1) {
				if (dir == 1) {
					// y
					v[x][y + j] = 0;
					door_v[x][y + j] = 1;
				} else {
					// x
					h[x + j][y] = 0;
					door_h[x + j][y] = 1;
				}
			}
		}

		// for (int i = 0; i < 5; i += 1) {
		// 	for (int j = 0; j < 5; j += 1) {
		// 		printf("%d,%d ", v[i][j], h[i][j]);
		// 	}
		// 	NL;
		// }
		
		pair<double, double> nemo;
		cin >> nemo.first >> nemo.second;

		if (nemo.first > 199 || nemo.second > 199) {
			puts("0");
			continue;
		}

		// cout << (int)nemo.first << " " << (int)nemo.second << endl;
		printf("%d\n", sssp({0, 0}, { (int)nemo.first, (int)nemo.second }));
	}
	return 0;
}