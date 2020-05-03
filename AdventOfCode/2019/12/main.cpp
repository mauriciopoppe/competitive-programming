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

class Particle {
public:
    vector<int> p;
    vector<int> v;
    Particle() {
        p = vector<int>(3, 0);
        v = vector<int>(3, 0);
    }

    void print() {
        printf("p=<%d,%d,%d> v=<%d,%d,%d>\n", p[0], p[1], p[2], v[0], v[1], v[2]);
    }

    void gravity(Particle &other) {
        for (int i = 0; i < 3; i += 1) {
            int change = 0;
            if (p[i] < other.p[i]) change = 1;
            if (p[i] > other.p[i]) change = -1;
            v[i] += change;
            other.v[i] -= change;
        }
    }

    void simulate() {
        for (int i = 0; i < 3; i += 1) {
            p[i] += v[i];
        }
    }

    int energy() {
        int total_p = 0;
        int total_v = 0;
        for (int i = 0; i < 3; i += 1) {
            total_p += abs(p[i]);
            total_v += abs(v[i]);
        }
        return total_p * total_v;
    }
};

void part1(vector<Particle> particles, int steps) {
    for (int step = 0; step < steps; step++) {
        for (int i = 0; i < particles.size(); i += 1) {
            for (int j = i + 1; j < particles.size(); j += 1) {
                particles[i].gravity(particles[j]);
            }
        }
//        cout << "\n";
        for (int i = 0; i < particles.size(); i += 1) {
            particles[i].simulate();
//            particles[i].print();
        }
    }

    int energy = 0;
    for (int i = 0; i < particles.size(); i += 1) {
        energy += particles[i].energy();
    }
    cout << energy << endl;
}

void part2(vector<Particle> particles) {
}

int main() {
    string line;
    vector<Particle> particles;
    while (getline(cin, line)) {
        Particle p;
        sscanf(line.c_str(), "<x=%d, y=%d, z=%d>", &p.p[0], &p.p[1], &p.p[2]);
//        p.print();
        particles.emplace_back(p);
    }
    part1(particles, 1000);
}
