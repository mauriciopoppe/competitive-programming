#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<int> gen(int iter) {
    vector<int> base = {0, 1, 0, -1};
    vector<int> out;
    int counter = 0;
    int total = 0;
    while (out.size() != 8) {
        for (int j = 0; j <= iter && out.size() != 8; j += 1) {
            if (total++ == 0) continue;
            out.push_back(base[counter]);
        }
        counter = counter + 1;
        counter %= 4;
    }

//    for (int i = 0; i < out.size(); i += 1) {
//        printf("%2d", out[i]);
//    }
//    printf("\n");
    return out;
}

vector<int> gen2(int iter, int offset) {
    vector<int> base = {0, 1, 0, -1};
    vector<int> out;
    int base_size = base.size() * iter;
    int k = offset / base_size;
    int start = offset - k * base_size;
    int counter = start / iter;
    int j_start = start % iter;

    printf("k=%d base_size=%d counter=%d j_start=%d\n", k, base_size, counter, j_start);

    int total = 0;
    while (out.size() != 8) {
        for (int j = j_start; j < iter && out.size() != 8; j += 1) {
            if (total++ == 0) continue;
            out.push_back(base[counter]);
        }
        counter = counter + 1;
        counter %= 4;
        j_start = 0;
    }

    for (int i = 0; i < out.size(); i += 1) {
        printf("%2d", out[i]);
    }
    printf("\n");
    return out;
}

void part2(string in, int iter) {
    int offset = 0;
    for (int i = 0; i < 7; i += 1) offset = offset * 10 + (in[i] - '0');

    int in_size = in.size();
    int k = offset / in_size;
    int start = offset - in_size * k;
    int end = start + 8;

    printf("k=%d offset=%d size=%d %d %d\n", k, offset, in_size, start, end);

    vector<int> n;
    for (int i = start; i < end; i += 1) {
        n.emplace_back(in[i % in.size()] - '0');
        printf("%d", n[n.size() - 1]);
    }
    printf("\n");

    for (int i = 0; i < iter; i += 1) {
        vector<int> next(n.size(), 0);
        for (int j = 0; j < n.size(); j += 1) {
            vector<int> mult = gen2(offset + j - 1, offset - 1);
            int c = 0;
            for (int k = 0; k < n.size(); k += 1) {
                c += mult[k] * n[k];
            }
            next[j] = abs(c) % 10;
        }
        n = next;
    }

    for (int i = 0; i < n.size(); i += 1) {
        printf("%d", n[i]);
    }
    printf("\n");

}

void part1(string in, int iter) {
    vector<int> n;
    for (int i = 0; i < in.size(); i += 1) {
        n.emplace_back(in[i] - '0');
    }

    for (int i = 0; i < iter; i += 1) {
        vector<int> next(n.size(), 0);
        for (int j = 0; j < n.size(); j += 1) {
            vector<int> mult = gen(j);
            int c = 0;
            for (int k = 0; k < n.size(); k += 1) {
                c += mult[k] * n[k];
            }
            next[j] = abs(c) % 10;
        }
        n = next;
    }

    for (int i = 0; i < 8; i += 1) {
        printf("%d", n[i]);
    }
    printf("\n");
}

int main() {
    string in;
    cin >> in;
//    part1(in, 100);
    part2(in, 100);
}