#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define M 201

struct state {
	vector<int> v;
	state(vector<int> _v) {
		v = _v;
	}
	state(int _a, int _b, int _c) {
		v.assign(3, 0);
		v[0] = _a;
		v[1] = _b;
		v[2] = _c;
	}
	bool operator<(const state &other) const {
		if (v[0] != other.v[0]) {
			return v[0] < other.v[0];
		}
		if (v[1] != other.v[1]) {
			return v[1] < other.v[1];
		} 
		return v[2] < other.v[2];
	}
};


pair<int, int> solve(vector<int> &max_value, int limit) {
	map<state, int> d;

	pair<int, int> best = {0, 0};

	state initial(0, 0, max_value[2]);

	// sum of weights + state
	set<pair<int, state> > q;
	d[initial] = 0;
	q.insert({ 0, initial });

	while (!q.empty()) {
		pair<int, state> top = *(q.begin());
		state &top_state = top.second;
		vector<int> &v = top_state.v;					
		q.erase(q.begin());

		for (int i = 0; i < 3; i += 1) {
			if (v[i] == limit) {
				return {top.first, limit};				
			}
			if (v[i] > best.second && v[i] < limit) {
				best = {top.first, v[i]};
			}
		}

		for (int i = 0; i < 3; i += 1) {
			for (int j = 0; j < 3; j += 1) {
				if (i != j) {
					int max_pour = max_value[j] - v[j];
					int weight = min(max_pour, v[i]);

					if (weight) {
						state new_state(v);
						// pour weight from i to j
						new_state.v[j] += weight;
						// remove weight from i
						new_state.v[i] -= weight;

						if (!d.count(new_state) || d[top_state] + weight < d[new_state]) {
							q.erase({ d[new_state], new_state });
							d[new_state] = d[top_state] + weight;
							q.insert({ d[new_state], new_state });
						}
					}
				}
			}
		}
	}

	return best;
}

int main() {
	int cas;
	int limit;
	vector<int> v(3);
	cin >> cas;
	while (cas--) {
		cin >> v[0] >> v[1] >> v[2] >> limit;
		pair<int, int> solution = solve(v, limit);
		printf("%d %d\n", solution.first, solution.second);
	}
	return 0;
}