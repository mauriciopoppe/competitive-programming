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
int part1_single(vector<int> m, int first_input, int second_input) {
    int i = 0;
    int first = 0;
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
            if (!first) {
                m[m[i + 1]] = first_input;
                first = 1;
            } else {
                m[m[i + 1]] = second_input;
            }
            i += 2;
        } else if (opcode == 4) {
//            cout << first_value << endl;
            if (m[i + 2] == 99) {
                return first_value;
            };
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
    return -1;
}

void part1(vector<int> numbers) {
    int best = 0;
    vector<int> input = {0, 1, 2, 3, 4};
    do {
        int last = 0;
        for (int i = 0; i < input.size(); i += 1) {
            last = part1_single(numbers, input[i], last);
        }
        best = max(best, last);
    } while (next_permutation(input.begin(), input.end()));
    cout << best << endl;
}

class Solution {
public:
    vector<int> m;
    int i;
    int first;
    int first_taken = false;
    int done = false;
    Solution(vector<int> _n, int _first):
        m(_n), i(0), first(_first) {}

    int run(int in) {
        while (m[i] != 99 && !done) {
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
                if (!first_taken) {
                    m[m[i + 1]] = first;
                    first_taken = 1;
                } else {
                    m[m[i + 1]] = in;
                }
                i += 2;
            } else if (opcode == 4) {
                if (m[i + 2] == 99) {
                    done = true;
                }
                i += 2;
                return first_value;
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
        return 99;
    }
};

void part2(vector<int> in) {
    int best = 0;
    vector<int> input = {5, 6, 7, 8, 9};
    do {
        vector<Solution> n = {
                Solution(in, input[0]),
                Solution(in, input[1]),
                Solution(in, input[2]),
                Solution(in, input[3]),
                Solution(in, input[4])
        };
        int last = 0;
        int cur = 0;
        do {
            last = n[cur].run(last);
            if (cur == 4) {
                best = max(best, last);
            }
            cur = (cur + 1) % 5;
            cout << last << endl;
        } while (last != 99);
        best = max(best, last);
    } while (next_permutation(input.begin(), input.end()));
    cout << best << endl;
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
    part1(numbers);
    part2(numbers);
}