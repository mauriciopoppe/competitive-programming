#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

template <typename Number>
Number GCD(Number u, Number v) {
    while (v != 0) {
        Number r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int solve(vector<string> mat, int r, int c) {
    set<pii> visible;
//    printf("%d %d %d\n", r, c);

    for (int i = 0; i < mat.size(); i += 1) {
        for (int j = 0; j < mat[0].size(); j += 1) {
            if (mat[i][j] == '#') {
                if (i == r && j == c) continue;
                int dx = i - r;
                int dy = j - c;
                int den = GCD(abs(dx), abs(dy));
                dx /= den;
                dy /= den;
                visible.insert(pii(dx, dy));
            }
        }
    }
    return visible.size();
}

void part1() {
    vector<string> mat;
    string row;
    while (cin >> row) {
        mat.emplace_back(row);
        cout << row << endl;
    }

    int best = 0;
    for (int i = 0; i < mat.size(); i += 1) {
        for (int j = 0; j < mat[0].size(); j += 1) {
            if (mat[i][j] == '#') {
                int candidate = solve(mat, i, j);
                if (candidate > best) {
                    best = candidate;
                    printf("best %d %d\n", i, j);
                }
            }
        }
    }

    cout << best;
}


int solve2(vector<string> mat, int r, int c) {
    map<float, pii> pos;
    map<pii, int> visible;

    for (int i = 0; i < mat.size(); i += 1) {
        for (int j = 0; j < mat[0].size(); j += 1) {
            if (mat[i][j] == '#') {
                if (i == r && j == c) continue;
                int dx = i - r;
                int dy = j - c;
                int den = GCD(abs(dx), abs(dy));
                dx /= den;
                dy /= den;
                int cnt = visible[pii(dx, dy)];
                float angle = atan2(dy, dx);
                if (dy < 0) angle += 3.14159265;
                pos[cnt * angle]
                visible[pii(dx, dy)]++;
            }
        }
    }
    return visible.size();
}

void part2() {
    vector<string> mat;
    string row;
    while (cin >> row) {
        mat.emplace_back(row);
        cout << row << endl;
    }
    int r = 19;
    int c = 23;
    solve2(mat, r, c);
}

int main() {
    part1();
}