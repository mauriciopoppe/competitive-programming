#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void part2() {
    int n;
    int total = 0;
    while (cin >> n) {
        while (n >= 0) {
            int candidate = (n = (n / 3) - 2);
            if (candidate >= 0) total += candidate;
        }
    }
    cout << total << endl;
}

void part1() {
    int n;
    int total = 0;
    while (cin >> n) {
        total += (n / 3) - 2;
    }
    cout << total << endl;
}

int main() {
//    part1();
    part2();
}