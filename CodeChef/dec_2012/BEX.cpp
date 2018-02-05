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

// BIT
#define M 100005
int tree[M + 10];

void update(int x) {
	while(x <= M) {
		tree[x] += 1;
		x += (x & -x);
	}
}

int read(int x){
	int sum = 0;
	while (x > 0) {
		sum += tree[x];
		x -= (x & -x);
	}
	return sum;
}

struct book {
	string name;
	int pos, rank;
	book(){}
	book(int _rank, string _name, int _pos) {
		rank = _rank;
		name = _name;
		pos = _pos;
	}
	bool operator <(const book &other)const {
		if(rank != other.rank) return rank > other.rank;
		return pos < other.pos;
	}
} b;

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int n, size, rank;
	string name;
	while(cin >> n) {
		memset(tree, 0, sizeof tree);
		size = 0;
		priority_queue<book> pq;
		while(n--) {
			cin >> rank;
			if (rank == -1) {
				b = pq.top();
				pq.pop();
				// printf("%d %d\n", size, b.pos);
				// printf("%d %d\n", read(size), read(b.pos));
				printf("%d %s\n", (size - b.pos) - (read(size) - read(b.pos)), b.name.c_str());
				update(b.pos);
			} else {
				cin >> name;
				if (rank == 0) continue;
				b = book(rank, name, ++size);
				pq.push(b);
			}
		}
	}
	return 0;
}