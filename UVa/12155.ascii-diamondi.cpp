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

char m[60][60];
int mul[] = {2, 1, 2, 1, 1, 2, 1, 2};
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void gen(int n) {
	F(i, 60) F(j, 60) m[i][j] = '.';
	int size = n * 2 - 1;
	int mid = n - 1;		
	int cnt;
	m[mid][mid] = 'a';
	char start = 'a' + n - 1;
	F(z, size) {
		char letter = start - z;
		cnt = 0;
		for (int i = z; i < n; i += 1, ++cnt) {
			m[i][mid + cnt] = m[i][mid - cnt] = letter;
		}
		cnt = 0;
		for (int i = size - 1 - z; i >= n; i -= 1, ++cnt) {
			m[i][mid + cnt] = m[i][mid - cnt] = letter;
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		gen(n);
		F(i, n * 2 - 1) {
			F(j, n * 2 - 1) {
				cout << m[i][j];
			}
			NL;
		}
	}
	return 0;
}