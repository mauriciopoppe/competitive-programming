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

constexpr ll ADD = 1;
constexpr ll MULT = 2;
constexpr ll IN = 3;
constexpr ll OUT = 4;
constexpr ll JUMP_IF_TRUE = 5;
constexpr ll JUMP_IF_FALSE = 6;
constexpr ll LESS_THAN = 7;
constexpr ll EQUALS = 8;
constexpr ll RELATIVE_BASE_ADJUST = 9;
constexpr ll HALT = 99;

constexpr ll POSITION_MODE  = 0;
constexpr ll IMMEDIATE_MODE = 1;
constexpr ll RELATIVE_MODE  = 2;

class Solution {
public:
    vector<ll> m;
    ll pc = 0;
    ll relative_base = 0;
    Solution(vector<ll> _n): m(_n) {}

    ll decode(vector<ll*> &out) {
        int inst = m[pc];
        int opcode = inst % 100; inst /= 100;
        int inst_operands = 0;
        switch(opcode) {
            case ADD:
            case MULT:
            case LESS_THAN:
            case EQUALS:
                inst_operands = 3;
                break;
            case JUMP_IF_TRUE:
            case JUMP_IF_FALSE:
                inst_operands = 2;
                break;
            case IN:
            case OUT:
            case RELATIVE_BASE_ADJUST:
                inst_operands = 1;
                break;
            default:
                break;
        }
        for (int j = 0; j < inst_operands; j += 1) {
            int mode = inst % 10; inst /= 10;
            switch (mode) {
                case POSITION_MODE:
                    out[j] = &(m[m[pc + j + 1]]);
                    break;
                case IMMEDIATE_MODE:
                    out[j] = &(m[pc + j + 1]);
                    break;
                case RELATIVE_MODE:
                    out[j] = &(m[m[pc + j + 1] + relative_base]);
                    break;
            }
        }
        return opcode;
    }

    bool run(ll in) {
        while (true) {
            vector<ll*> params(4);
            ll op = decode(params);
            switch(op) {
                case ADD:
                    *params[2] = *params[0] + *params[1];
                    pc += 4;
                    break;
                case MULT:
                    *params[2] = *params[0] * *params[1];
                    pc += 4;
                    break;
                case IN:
                    *params[0] = in;
                    pc += 2;
                    break;
                case OUT:
                    cout << *params[0] << "\n";
                    pc += 2;
                    break;
                case JUMP_IF_TRUE:
                    pc = (*params[0]) ? *params[1] : pc + 3;
                    break;
                case JUMP_IF_FALSE:
                    pc = (!*params[0]) ? *params[1] : pc + 3;
                    break;
                case LESS_THAN:
                    *params[2] = (*params[0] < *params[1]);
                    pc += 4;
                    break;
                case EQUALS:
                    *params[2] = (*params[0] == *params[1]);
                    pc += 4;
                    break;
                case RELATIVE_BASE_ADJUST:
                    relative_base += *params[0];
                    pc += 2;
                    break;
                case HALT:
                    return true;
                default:
                    cout << "Unknown code\n";
            }
        }
    }
};

void part1(vector<ll> numbers) {
    Solution sol(numbers);
    sol.run(1);
}

void part2(vector<ll> numbers) {
    Solution sol(numbers);
    sol.run(2);
}

int main() {
    string input;
    string token;
    vector<ll> numbers(1000000, 0);
    int i = 0;
    while (getline(cin, input)) {
        stringstream tokenizer(input);
        while (getline(tokenizer, token, ',')) {
            numbers[i++] = stoll(token);
        }
    }
//    part1(numbers);
    part2(numbers);
}