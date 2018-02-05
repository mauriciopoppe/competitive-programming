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

vector<string> queries;
vector<string> solution(10);
vector<vi> v(10, vi());

map<pii, string> dp;

int bs(vi v, int i) {
	if (!v.size()) {
		return -1;
	}
	int low = -1, high = v.size() - 1;
	int mid;
	while (high - low > 1) {
		mid = low + (high - low) / 2;
		if (v[mid] > i) high = mid;
		else low = mid;
	}
	if (v[mid] > i) return v[mid];
	return -1;
}

string solve(int digit, int index) {
	int q_index = bs(v[digit], index);
	if (dp.find(pii(digit, index)) != dp.end()) {
		return dp[pii(digit, index)];
	}

	if (q_index < 0) {
		stringstream ss;
		ss << digit;
		return ss.str();
	}
	string sol = "";
	string query = queries[q_index];
	F(i, query.size()) {
		sol += solve(query[i] - '0', q_index);
	}
	return dp[pii(digit, index)] = sol;
}

int main() {
	string start, transformation;
	cin >> start;
	int n_queries, digit;
	cin >> n_queries;
	F(i, n_queries) {
		scanf("%d->", &digit);
		getline(cin, transformation);
		queries.push_back(transformation);
		v[digit].push_back(i);
	}
	F(i, 10) {
		solution[i] = solve(i, -1);
		// cout << solution[i] << endl;
	}
	LL total = 0;
	F(i, start.size()) {
		string s = solution[start[i] - '0'];
		F(j, s.size()) {
			total *= 10LL;
			total += s[j] - '0';
			total %= 1000000007LL;
		}
	}
	cout << total << endl;
	return 0;
}