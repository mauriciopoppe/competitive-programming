#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<LL> vi;

int indexMin;

struct Sereja {
	vi v;
	int index;
	LL sm;

	Sereja() {}

	Sereja(int _size, int _index) {
		v.resize(_size);
		index = _index;
		sm = 0;
	}

	void read(int s) {
		sm = 0;
		F(i, s) scanf("%lld", &v[i]), sm += v[i];
	}

	bool operator <(const Sereja &other) const {
		return v[indexMin] < other.v[indexMin];
	}

	bool leq(const Sereja &other) {
		int size = v.size();
		for (int i = 0; i < size; i += 1) {
			if (v[i] > other.v[i]) return false;
		}	
		return true;
	}

	void add(const Sereja &other, int mult) {
		int size = v.size();
		for (int i = 0; i < size; i += 1) {
			v[i] += other.v[i] * mult;
		}
	}

	void calcSm() {
		sm = 0;
		int size = v.size();
		for (int i = 0; i < size; i += 1) {
			sm += v[i];
		}
	}
};

Sereja operator+(const Sereja &a, const Sereja &b) {
	int size = a.v.size();
	Sereja c(size, 0);
	for (int i = 0; i < size; i += 1) {
		c.v[i] = a.v[i] + b.v[i];
	}
	return c;
}

Sereja operator-(const Sereja &a, const Sereja &b) {
	int size = a.v.size();
	Sereja c(size, 0);
	for (int i = 0; i < size; i += 1) {
		c.v[i] = a.v[i] - b.v[i];
	}
	return c;
}

bool operator==(const Sereja &a, const Sereja &b) {
	int size = a.v.size();
	if (a.sm != b.sm) return false;
	for (int i = 0; i < size; i += 1) {
		if (a.v[i] != b.v[i]) return false;
	}
	return true;
}

vector<Sereja> v;
Sereja wanted;
int r, c;
LL wantedSum;
int mi[100010];

void printSereja(Sereja s) {
	TR(s.v, it) {
		printf(" %lld", *it);
	}
	NL;
}

map<LL, vector<int> > mS;
bool addable(Sereja &res, set<int> &s, int i) {
	Sereja diff = res - wanted;
	printSereja(res);
	printSereja(wanted);

	diff.calcSm();

	vector<int> &serejasBySum = mS[diff.sm];
	// printSereja(diff);
	// printf("SET\n");
	// TR(s, it) printf(" %d", *it); NL;
	// TR(serejasBySum, it) {
	// 	if (s.find(it->index) == s.end()) continue;
 // 		int indexInV = mi[it->index];
	// 	// printf("indexInV %d\n", indexInV);
	// 	// printSereja(v[indexInV]);
	// 	if (v[indexInV] == diff) {
	// 		// printf("!!! %d\n", indexInV);
	// 		s.erase(it->index);
	// 		return true;
	// 	}
	// }
	return false;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int cas;
	cin >> cas;

	while (cas--) {
		scanf("%d%d", &r, &c);
		v.clear();
		mS.clear();
		// printf 
		F(i, r) {
			Sereja s(c, i);
			F(j, c) scanf("%lld", &s.v[j]), s.sm += s.v[j];
			if (mS.find(s.sm) == mS.end()) mS[s.sm] = vector<int>();
			mS[s.sm].push_back(s.index);
			v.push_back(s);
		}

		indexMin = 0;
		wanted.v = vi(c);
		wanted.sm = 0;
		F(j, c) {
			scanf("%lld", &wanted.v[j]);
			wanted.sm += wanted.v[j];
			if (wanted.v[j] < wanted.v[indexMin]) indexMin = j;
		}

		sort(ALL(v));
		for (int i = 0; i < r; i += 1) {
			// printf ("map %d -> %d\n", v[i].index, i);
			mi[v[i].index] = i;
		}


		Sereja start;
		start.v = vi(c, 0);
		set<int> sol;
		for(int i = 0; i < r; i += 1) {
			start.add(v[i], 1);
			if (start.leq(wanted)) {
				sol.insert(v[i].index);
			// } else if (addable(start, sol, i)) {
			// 	sol.insert(v[i].index);
			} else {
				start.add(v[i], -1);
			}
		}
		if (sol.size() < 2) {
			puts("0");
			continue;
		}

		printf("%d\n", (int)sol.size());
		int space = 0;
		TR(sol, it) {
			if (space++) printf(" ");
			printf ("%d", *it + 1);
		}
		NL;
	}
	return 0;
}