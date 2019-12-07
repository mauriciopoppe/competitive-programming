#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void print(vector<int> m) {
    for (int i = 0; i < m.size(); i += 1) {
        printf(" %2d", m[i]);
    }
    printf("\n");
}

void part2(vector<int> m, int input) {
    int i = 0;
    while (m[i] != 99) {
        int n = m[i];
        int opcode = n % 100; n /= 100;
        int first_mode = n % 10; n /= 10;
        int second_mode = n % 10; n /= 10;
        int first_value = first_mode == 0 ? m[m[i + 1]] : m[i + 1];
        int second_value = second_mode == 0 ? m[m[i + 2]] : m[i + 2];

        if (opcode == 1) {
            m[m[i + 3]] = first_value + second_value;
            i += 4;
        } else if (opcode == 2) {
            m[m[i + 3]] = first_value * second_value;
            i += 4;
        } else if (opcode == 3) {
            m[m[i + 1]] = input;
            i += 2;
        } else if (opcode == 4) {
            cout << first_value << endl;
            if (m[i + 2] == 99) break;
            i += 2;
        } else if (opcode == 5 || opcode == 6) {
            if ((first_value != 0 && opcode == 5) || (first_value == 0 && opcode == 6)) {
                i = second_value;
            } else {
                i += 3;
            }
        } else if (opcode == 7) {
            if (first_value < second_value) {
                m[m[i + 3]] = 1;
            } else {
                m[m[i + 3]] = 0;
            }
            i += 4;
        } else if (opcode == 8) {
            if (first_value == second_value) {
                m[m[i + 3]] = 1;
            } else {
                m[m[i + 3]] = 0;
            }
            i += 4;
        }
    }
}

void part1(vector<int> m, int input) {
    int i = 0;
    while (m[i] != 99) {
        int n = m[i];
        int opcode = n % 100; n /= 100;
        int first_mode = n % 10; n /= 10;
        int second_mode = n % 10; n /= 10;
        int first_value = first_mode == 0 ? m[m[i + 1]] : m[i + 1];
        int second_value = second_mode == 0 ? m[m[i + 2]] : m[i + 2];

        if (opcode == 1) {
            m[m[i + 3]] = first_value + second_value;
            i += 4;
        } else if (opcode == 2) {
            m[m[i + 3]] = first_value * second_value;
            i += 4;
        } else if (opcode == 3) {
            m[m[i + 1]] = input;
            i += 2;
        } else if (opcode == 4) {
            cout << first_value << endl;
            if (m[i + 2] == 99) break;
            i += 2;
        }
    }
}

int main() {
    string input;
    string token;
    vector<int> numbers;
    while (getline(cin, input)) {
        stringstream tokenizer(input);
        while (getline(tokenizer, token, ',')) {
            int n = stoi(token);
            numbers.emplace_back(n);
        }
    }
//    part1(numbers, 1);
    part2(numbers, 5);
}