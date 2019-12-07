#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void part2(vector<int> clone) {
    for (int noun = 0; noun < 100; noun += 1) {
        for (int verb = 0; verb < 100; verb += 1) {
            int i = 0;
            vector<int> input = clone;
            input[1] = noun;
            input[2] = verb;
            while (input[i] != 99) {
                if (input[i] == 1) {
                    input[input[i + 3]] = input[input[i + 1]] + input[input[i + 2]];
                } else if (input[i] == 2) {
                    input[input[i + 3]] = input[input[i + 1]] * input[input[i + 2]];
                }
                i += 4;
            }
            if (input[0] == 19690720) {
                cout << 100 * noun + verb << endl;
            }
        }
    }

}

void part1(vector<int> input) {
    int i = 0;
    input[1] = 12;
    input[2] = 2;
    while (input[i] != 99) {
        if (input[i] == 1) {
            input[input[i + 3]] = input[input[i + 1]] + input[input[i + 2]];
        } else if (input[i] == 2) {
            input[input[i + 3]] = input[input[i + 1]] * input[input[i + 2]];
        }
        i += 4;
    }
    cout << input[0] << endl;
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
//    part1(numbers);
    part2(numbers);
}