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
typedef vector<int> vi;
#define M 1010

int next[M + 10];
int taken[M * M];
int pos[M * M];
int kcg[M * M];

int find_next(int i) {
	while (taken[i * next[i]]) next[i]++;
	return next[i];
}

int min_factor(int n) {
	int index = n,
		k,
		candidate,
		best = find_next(n) * n;

	for (int i = 2; i * i <= n; i += 1) {
		if (n % i == 0) {
			k = i;
			candidate = find_next(k) * k;
			if (candidate < best) {
				best = candidate;
				index = k;
			}

			k = n / i;
			candidate = find_next(k) * k;
			if (candidate < best) {
				best = candidate;
				index = k;
			}
		}
	}
	return index;
}

void generate() {	
	MS(taken, 0);
	taken[1] = kcg[1] = 1;
	taken[2] = kcg[2] = 2;
	int mx = 100;

	for (int i = 3; i <= mx; i += 1) {
		int index = min_factor(kcg[i - 1]);
		kcg[i] = index * next[index];
		next[index]++;
		taken[kcg[i]] = 1;
	}


	// calculate positions
	for (int i = 1; i <= mx; i += 1) {
		printf("%d ", kcg[i]);
		pos[kcg[i]] = i;
	}
	NL;
}

int main() {
	F(i, M) next[i] = 1;
	next[2] = 2;
	generate();
	puts("end");

	int n;
	while(cin >> n) {
		printf("The number %d appears in location %d.\n", n, pos[n]);
	}
	return 0;
}