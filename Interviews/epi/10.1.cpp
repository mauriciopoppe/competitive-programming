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

int is_balanced(Node *current, bool &balanced) {
	if (!balanced) {
		return -1;
	}
	if (!current) {
		return 0;
	}

	int left_height = is_balanced(current->left, balanced);
	int right_height = is_balanced(current->right, balanced);
	int height = max(left_height, right_height);
	if (abs(left_height - right_height) > 1) {
		balanced = false;
	}
	return height + 1;
}

void is_balanced(Node *n) {
	bool balanced = true;
	is_balanced(n, balanced);
	cout << balanced << endl;
}

int main() {
	
	return 0;
}