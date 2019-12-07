#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define X(p) (p.first)
#define Y(p) (p.second)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void part2(map<pii, int> one, map<pii, int> two) {
    int best = 1e9;
    for (auto &it: one) {
        if (two[it.first]) {
            best = min(best, it.second + two[it.first]);
        }
    }
//    for (auto &it: two) {
//        if (one[it.first]) {
//            best = min(best, it.second + one[it.first]);
//        }
//    }
    cout << best << endl;
}

void part1(vector<pii> one, vector<pii> two) {
    int best = 1e9;
    map<pii, bool> taken;
    for (int i = 1; i < one.size(); i += 1) {
        pii a = one[i - 1];
        pii b = one[i];
        if (X(a) == X(b)) {
            for (int y = min(Y(a), Y(b)); y <= max(Y(a), Y(b)); y += 1) {
                taken[pii(X(a), y)] = true;
            }
        } else {
            for (int x = min(X(a), X(b)); x <= max(X(a), X(b)); x += 1) {
                taken[pii(x, Y(a))] = true;
            }
        }
    }

    for (int i = 1; i < two.size(); i += 1) {
        pii a = two[i - 1];
        pii b = two[i];
        if (X(a) == X(b)) {
            for (int y = min(Y(a), Y(b)); y <= max(Y(a), Y(b)); y += 1) {
                pii c(X(a), y);
                int diff = abs(X(c)) + abs(Y(c));
                if (taken[c] && diff > 0) {
                    best = min(best, diff);
                }
            }
        } else {
            for (int x = min(X(a), X(b)); x <= max(X(a), X(b)); x += 1) {
                pii c(x, Y(a));
                int diff = abs(X(c)) + abs(Y(c));
                if (taken[c] && diff > 0) {
                    best = min(best, diff);
                }
            }
        }
    }
    cout << best << endl;
}

map<pii, int> read_two() {
    string input;
    string token;

    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    int total = 0;

    map<pii, int> taken = {};

    getline(cin, input);
    stringstream tokenizer(input);
    int n;
    char dir;
    while (getline(tokenizer, token, ',')) {
        stringstream instruction(token);
        instruction >> dir >> n;
        dx = 0; dy = 0;
        if (dir == 'L') dx = -1;
        if (dir == 'R') dx = 1;
        if (dir == 'U') dy = 1;
        if (dir == 'D') dy = -1;
        while (n--) {
            x += dx;
            y += dy;
            total++;
            if (!taken[pii(x, y)]) {
                taken[pii(x, y)] = total;
            }
        }
    }

    return taken;
}

vector<pii> read() {
    string input;
    string token;
    vector<pii> points;
    points.emplace_back(pii(0, 0));
    getline(cin, input);
    stringstream tokenizer(input);
    int n;
    char dir;
    while (getline(tokenizer, token, ',')) {
        stringstream instruction(token);
        instruction >> dir >> n;
        pii next = points[points.size() - 1];
        if (dir == 'L') next.first -= n;
        if (dir == 'R') next.first += n;
        if (dir == 'U') next.second += n;
        if (dir == 'D') next.second -= n;
        points.emplace_back(next);
    }

    for (auto &a: points) {
        printf("<%d, %d> ", a.first, a.second);
    }
    printf("\n");

    return points;
}

int main() {
//    vector<pii> one = read();
//    vector<pii> two = read();
//    part1(one, two);

    map<pii, int> one = read_two();
    map<pii, int > two = read_two();
    part2(one, two);
}
