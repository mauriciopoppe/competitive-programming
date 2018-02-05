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

// -1 search on the left of source (in the next iteration)
// 1 search on the right of source (in the next iteration)
// 0 solution found!
int f(int value, int missing, vector<int> &source) {
	int leq = missing - 1;
	int geq = missing;

	if (!missing) {
		if (!source.size()) {
			return 0;
		}
		return source[0] < value ? 1 : 0;
	}

	if (leq >= source.size()) {
		return -1;
	}
	if (source[leq] > value) {
		return -1;
	}
	if (geq < source.size() && source[geq] < value) {
		return 1;
	}
	return 0;
}

int find_value(vector<int> &a, vector<int> &b, int k) {
	int low = 0, high = min(k, (int)a.size());
	// cout << "START" << endl;
	while (high - low > 1) {
		int mid = low + (high - low) / 2;
		int partition = f(a[mid], k - (mid + 1), b);
		// cout << mid << " " << partition << endl;
		if (!partition) {
			return a[mid];
		}
		if (partition < 1) {
			low = mid;
		} else {
			high = mid;
		}
	}
	if (low < a.size() && !f(a[low], k - (low + 1), b)) {
		return a[low];
	}

	return -1;
}

int find_kth(vector<int> &a, vector<int> &b, int k) {
	int in_a = find_value(a, b, k);
	int in_b = find_value(b, a, k);
	// cout << in_a << " " << in_b << endl;
	return in_a > 0 ? in_a : in_b;
}

int main() {
	int ta[] = {1,3,5,7,10};
	vector<int> a(ta, ta + 5);
	int tb[] = {2,2,9,9,9};
	vector<int> b(tb, tb + 5);
	// cout << find_kth(a, b, 1) << endl;;
	// cout << find_kth(a, b, 2) << endl;;
	// cout << find_kth(a, b, 3) << endl;;
	// cout << find_kth(a, b, 4) << endl;;
	// cout << find_kth(a, b, 5) << endl;;
	// cout << find_kth(a, b, 6) << endl;;
	// cout << find_kth(a, b, 7) << endl;;
	return 0;
}