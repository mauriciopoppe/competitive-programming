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

void partition(vector<int> &v, int n, int pivot_index) {
	int pivot = v[pivot_index];
	
	int less_index = 0;
	for (int i = 0; i < n; i += 1) {
		if (v[i] < pivot) {
			swap(v[less_index++], v[i]);
		}		
	}

	int right_index = n - 1;
	for (int i = n - 1; i >= 0; i -= 1) {
		if (v[i] > pivot) {
			swap(v[i], v[right_index--]);
		}
	}

	for (int i = 0; i < n; i += 1) {
		cout << v[i] << " -> ";
	}
	cout << endl;
}

int main() {
	int a[] = {5,3,7,3,1,7,5,9,8,5};
	vector<int> v(a, a + sizeof a / sizeof a[0]);
	partition(v, v.size(), 0);
	return 0;
}