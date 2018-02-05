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

void reverse_words(string w) {

	for (int i = 0; i < w.size() / 2; i += 1) {
		swap(w[i], w[w.size() - i - 1]);
	}
	// reverse words
	int i = 0;
	int j;
	while (w[i]) {
		while (!isalpha(w[i])) ++i;
		j = i;
		while (isalpha(w[j])) ++j;
		int k = j - 1;
		while (i < k) {
			swap(w[i++], w[k--]);
		}
		i = j;
	} 
	cout << w << endl;
}

int main() {
	reverse_words("Bob    likes  Alice ds , fs");
	return 0;
}