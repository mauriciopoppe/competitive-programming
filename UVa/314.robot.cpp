#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct cv {
  int d;
  int o;
  int x;
  int y;
  cv() {};
  cv(int _x, int _y, int _d, int _o) {
    x = _x;
    y = _y;
    d = _d;
    o = _o;
  }
  bool operator<(const cv &other) const {
    if (d == other.d) return o > other.o;
    return d > other.d;
  }
};

bool can_move(vector<vi> &input, int r, int c) {
  int mrows = input.size();
  int mcols = input[0].size();
  int lr = r;
  int lc = c;
  int hr = lr + 1;
  int hc = lc + 1;
  if (lr < 0 || lr >= mrows) return false;
  if (lc < 0 || lc >= mcols) return false;
  if (hr < 0 || hr >= mrows) return false;
  if (hc < 0 || hc >= mcols) return false;
  return input[lr][lc] + input[lr][hc] + input[hr][lc] + input[hr][hc] == 0;
}

int solve(vector<vi> &input, cv start, cv end, string initial_orientation) {
  map<string, int> ori = {{"north", 0}, {"east", 1}, {"south", 2}, {"west", 3}};
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int d[51][51][4];
  int visited[51][51][4];
  for (int i = 0; i < 51; i += 1) {
    for (int j = 0; j < 51; j += 1) {
      for (int k = 0; k < 4; k += 1) {
        d[i][j][k] = INF;
        visited[i][j][k] = false;
      }
    }
  }

  d[start.x][start.y][ori[initial_orientation]] = 0;
  priority_queue<cv> q;
  q.push(cv(start.x, start.y, 0, ori[initial_orientation]));
  while (!q.empty()) {
    cv top = q.top();
    q.pop();
    int &t = visited[top.x][top.y][top.o];
    if (t) continue;
    if (top.x == end.x && top.y == end.y) continue;
    t = true;

    // printf("[%d, %d] o=%d d=%d\n", top.x, top.y, top.o, top.d);

    for (int i = 0; i < 4; i += 1) {
      for (int j = 1; j <= 3; j += 1) {
        int cd = 1;
        if ((top.o - 1 + 4) % 4 == i ||
            (top.o + 1) % 4 == i) {
          cd += 1;
        } else if ((top.o + 2) % 4 == i) {
          cd += 2;
        }
        int nx = top.x + j * dx[i];
        int ny = top.y + j * dy[i];
        // printf("testing %d, %d\n", nx, ny);
        if (!can_move(input, nx, ny)) {
          break;
        }
        if (d[nx][ny][i] > cd + d[top.x][top.y][top.o]) {
          d[nx][ny][i] = cd + d[top.x][top.y][top.o];
          // printf("(%d,%d) -> (%d,%d), old or = %d, new or = %d, d = %d\n",
          //     top.x, top.y, nx, ny, top.o, i, d[nx][ny][i]);
          q.push(cv(nx, ny, d[nx][ny][i], i));
        }
      }
    }
  }
  int mn = INF;
  for (int i = 0; i < 4; i += 1) {
    mn = min(mn, d[end.x][end.y][i]);
  }
  return mn == INF ? -1 : mn;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c;
  while (cin >> r >> c) {
    if (r == 0 && c == 0) {
      break;
    }
    vector<vi> graph(r, vi(c, 0));
    for (int i = 0; i < r; i += 1) {
      for (int j = 0; j < c; j += 1) {
        cin >> graph[i][j];
      }
    }
    cv start, end;
    string orientation;
    cin >> start.x >> start.y;
    cin >> end.x >> end.y;
    start.x--; start.y--;
    end.x--; end.y--;
    cin >> orientation;
    printf("%d\n", solve(graph, start, end, orientation));
  }
}
