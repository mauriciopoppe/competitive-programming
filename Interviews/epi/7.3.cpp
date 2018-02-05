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

map<int, string> words;

void backtrack(string dest, string phone, int index) {
	if (index == phone.size()) {
		// print the word
		cout << dest << endl;
	} else {
		string mapped_word = words[phone[index] - '0'];
		for (int i = 0; i < mapped_word.size(); i += 1) {
			dest[index] = mapped_word[i];
			backtrack(dest, phone, index + 1);
		}
	}
}

void all_possible(string phone) {
	words[2] = "ABC";
	words[3] = "DEF";
	words[4] = "GHI";
	words[5] = "JKL";
	words[6] = "MNO";
	words[7] = "PQRS";
	words[8] = "TUV";
	words[9] = "WXYZ";
	string dest(phone.size(), '\0');
	backtrack(dest, phone, 0);
}


int main() {
	all_possible("2276696");
	return 0;
}