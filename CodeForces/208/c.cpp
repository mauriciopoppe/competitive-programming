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

int main() {
	int n;
	while (cin >> n) {
		vector<string> sol;
		vi v(n);
		vi zeros;
		zeros.push_back(-1);
		F(i, n) {
			cin >> v[i];
			if (v[i] == 0) zeros.push_back(i);
		}
		zeros.push_back(n);
		for (int i = 1; i < zeros.size(); i += 1) {
			priority_queue<pii> pq;
			stack<int> st;
			deque<int> dq;
			queue<int> q;

			for (int j = zeros[i - 1] + 1; j < zeros[i]; j += 1) {
				pq.push(pii(v[j], j));
			}

			map<int, int> best;
			int total = 1;
			while (best.size() < 3 && pq.size()) {
				pii top = pq.top();
				pq.pop();
				// printf("%d %d\n", top.first, top.second);
				best[top.second] = total++;
			}

			for (int j = zeros[i - 1] + 1; j < zeros[i]; j += 1) {
				if (best[j]) {
					int step = best[j];
					// printf("step is %d\n", step);
					if (step == 1) {
						q.push(v[j]);
						puts("pushQueue");
					} else {
						if (step == 2) {
							st.push(v[j]);
							puts("pushStack");							
						} else {
							dq.push_front(v[j]);
							puts("pushFront");
						}
					}
				} else {
					dq.push_back(v[j]); puts("pushBack");
				}
			}

			if (i != zeros.size() - 1) {
				int size = 0;
				string res = "";
				if (st.size()) res += " popStack", size++; 
				if (q.size()) res += " popQueue", size++; 
				if (dq.size()) res += " popFront", size++; 

				cout << size << res << endl;
			}
		}
	}
	return 0;
}