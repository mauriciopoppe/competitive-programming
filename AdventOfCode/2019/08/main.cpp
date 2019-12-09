#include <bits/stdc++.h>
using namespace std;

#define F(i,u) for (int i = (0); i < (u); i++)
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void part1() {
    int layers[100][30][30];
    memset(layers, 0, sizeof layers);

    string in;
    cin >> in;
    int n_layers = in.size() / 25 / 6;

    int it = 0;
    int best = 1e9;
    int result = 0;
    for (int i = 0; i < n_layers; i += 1) {
        pii digits(0, 0);
        int local_best = 0;
        for (int r = 0; r < 6; r += 1) {
            for (int c = 0; c < 25; c += 1) {
                int cur = layers[i][r][c] = in[it++] - '0';
                if (cur == 0) local_best++;
                if (cur == 1) digits.first++;
                if (cur == 2) digits.second++;
            }
        }
        if (local_best < best) {
            best = local_best;
            result = digits.first * digits.second;
        }
    }
    cout << result << endl;
}


void part2() {
    int layers[30][30];
    memset(layers, -1, sizeof layers);

    string in;
    cin >> in;
    int n_layers = in.size() / 25 / 6;

    int it = 0;
    for (int i = 0; i < n_layers; i += 1) {
        for (int r = 0; r < 6; r += 1) {
            for (int c = 0; c < 25; c += 1) {
                int candidate = in[it++] - '0';
                if (layers[r][c] == -1 || layers[r][c] == 2) layers[r][c] = candidate;
            }
        }
    }

    for (int r = 0; r < 6; r += 1) {
        for (int c = 0; c < 25; c += 1) {
            if (layers[r][c] == 0) cout << " ";
            else cout << "X";
        }
        cout << endl;
    }
}

int main() {
    part2();
}