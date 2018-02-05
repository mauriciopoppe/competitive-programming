#include <bits/stdc++.h>
#define INF int(1e9*2)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

string input;
int mat[201][201];

void BtoD(string &sol, int x1, int y1, int x2, int y2) { // not inc
  // printf("[%d %d - %d %d] = ", x1, y1, x2, y2);
  int sum = 0;
  int rows = x2 - x1;
  int cols = y2 - y1;
  for (int i = x1; i < x2; i += 1) {
    for (int j = y1; j < y2; j += 1) {
      sum += mat[i][j];
    }
  }

  if (sum == 0) {
    sol += '0';
    // printf("\n");
  } else if (sum == rows * cols) {
    sol += '1';
    // printf("1");
    // printf("\n");
  } else {
    int left = cols - cols / 2;
    int top = rows - rows / 2;

    sol += 'D';
    // printf("D");
    // printf("\n");
    BtoD(sol, x1, y1, x1 + top, y1 + left);
    if (cols > 1)
      BtoD(sol, x1, y1 + left, x1 + top, y2);
    if (rows > 1)
      BtoD(sol, x1 + top, y1, x2, y1 + left);
    if (cols > 1 && rows > 1)
      BtoD(sol, x1 + top, y1 + left, x2, y2);
  }
}

void DtoB(int &index, int x1, int y1, int x2, int y2) {
  char c = input[index++];
  if (c == '\0') return;
  int rows = x2 - x1;
  int cols = y2 - y1;
  int left = cols - cols / 2;
  int top = rows - rows / 2;
  if (c == 'D') {
    DtoB(index, x1, y1, x1 + top, y1 + left);
    if (cols > 1) {
      DtoB(index, x1, y1 + left, x1 + top, y2);
    }
    if (rows > 1)
      DtoB(index, x1 + top, y1, x2, y1 + left);
    if (cols > 1 && rows > 1)
      DtoB(index, x1 + top, y1 + left, x2, y2);
  } else {
    int el = c - '0';
    for (int i = x1; i < x2; i += 1) {
      for (int j = y1; j < y2; j += 1) {
        mat[i][j] = el;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string line, type, last = "";
  int row, col;
  while (true) {
    if (last == "") getline(cin, line);
    else line = last;
    if (line == "#") break;

    istringstream ss(line);
    ss >> type >> row >> col;
    // printf("[%s %d %d]\n", type.c_str(), row, col);
    input = "";
    while (getline(cin, last)) {
      // cout << last << endl;
      if (last.find(" ") != string::npos) break;
      if (last == "#") break;
      input += last;
    }
    // cout << input << "\n";
    // break;
    // cin >> row >> col;
    // cin >> input;

    printf("%s%4d%4d\n", type == "B" ? "D" : "B", row, col);

    string sol = "";

    if (type == "B") {
      for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
          mat[i][j] = input[i * col + j] - '0';
        }
      }
      BtoD(sol, 0, 0, row, col);
    } else {
      int index = 0;
      DtoB(index, 0, 0, row, col);
      for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
          sol += mat[i][j] + '0';
        }
      }
    }

    for (int i = 0; i < sol.size(); i += 1) {
      printf("%c", sol[i]);
      if ((i + 1) % 50 == 0) printf("\n");
    }
    if ((sol.size() % 50) != 0) printf("\n");
  }
}
