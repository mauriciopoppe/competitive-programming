#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int good(int n) {
    // first rule
    vector<int> v;
    while (n) {
        v.emplace(v.begin(), n % 10);
        n /= 10;
    }
    // first rule
    for (int i = 1; i < v.size(); i += 1) {
        if (v[i] < v[i - 1]) return 0;
    }
    int adj = 0;
    for (int i = 1; i < v.size(); i += 1) {
        if (v[i] == v[i - 1]) adj++;
    }
    if (adj == 0) return 0;
    return 1;
}

void part1(int l, int h) {
    int total = 0;
    for (int i = l; i <= h; i += 1) {
        if (good(i)) total++;
    }
    cout << total << endl;
}

int good2(int n) {
    vector<int> v;
    while (n) {
        v.emplace(v.begin(), n % 10);
        n /= 10;
    }
    for (int i = 1; i < v.size(); i += 1) {
        if (v[i] < v[i - 1]) return 0;
    }
    int adj = 0;
    int has_valid_adj = 0;
    for (int i = 1; i <= v.size(); i += 1) {
        if (i == v.size()) {
            if (adj == 1) has_valid_adj = 1;
        } else {
            if (v[i] == v[i - 1]) adj++;
            else {
                if (adj == 1) has_valid_adj = 1;
                adj = 0;
            }
        }
    }
    return has_valid_adj;
}

void part2(int l, int h) {
    int total = 0;
    for (int i = l; i <= h; i += 1) {
        if (good2(i)) total++;
    }
    cout << total << endl;
}

int main() {
//    cout << good(123789) << endl;
//    cout << good(223450) << endl;
//    cout << good(111111) << endl;
//
//    part1(273025, 767253);

    cout << good2(112233) << endl;
    cout << good2(123444) << endl;
    cout << good2(111122) << endl;

    part2(273025, 767253);
}