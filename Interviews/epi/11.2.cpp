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

void get_dist(tuple<double, double, double> t) {
	return sqrt(
		get<0>(t) * get<0>(t) +
		get<1>(t) * get<1>(t) +
		get<2>(t) * get<2>(t)
	);
}

void solve(vector<tuple<double, double, double> > points, int k) {
	priority_queue<double> pq;
	for (int i = 0; i < points.size(); i += 1) {
		double dist = get_dist(points[i]);
		pq.push(dist);
		if (pq.size() > k) {
			pq.pop();
		}
	}
	// print all elements in the priority queue
}


int main() {
	
	return 0;
}