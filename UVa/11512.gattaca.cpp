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

//Suffix Array + LCP
#define MAXN 1000005
int size;                   //size of the string
int t;                      //pow 2 helper
int sa[MAXN];
int sai[MAXN];
int lcp[MAXN];
 
/*
 * str is the initial string concatenated with '$'
 */
char str[MAXN];
 
void fix_index(int *b, int *e) {
	int p, np, op, diff, bs;
	p = sai[*b + t];
	bs = e - b;
	diff = 0;
	op = b - sa;
	F(i, bs) {
		if (((np = sai[*b + t]) != p) && !(op <= p && np < op + bs)) {
			p = np;
			diff = i;
		}
		sai[*(b++)] = op + diff;
	}
}

bool comp(int i, int j) {
	return sai[i + t] < sai[j + t];
} 

void suffix_array() {
	int i, j;
	int cnt[256];
	memset(cnt, 0, sizeof cnt);
	F(i, size) ++cnt[int(str[i])];
	for (i = 1; i < 256; i += 1) cnt[i] += cnt[i - 1];
	F(i, size) sa[--cnt[int(str[i])]] = i;
	for (i = size - 1; i >= 0; --i) sai[i] = cnt[int(str[i])];
	for (t = 1; t < size; t *= 2) {
		for (i = 0, j = 1; i < size; i = j++) {
			while(j < size && sai[sa[j]] == sai[sa[i]]) {
             	++j;
            }
            if (j - i > 1) {
            	sort(sa + i, sa + j, comp);
            	fix_index(sa + i, sa + j);
            }
        }
	}
}

pii string_match(char *p) {
	int lo = 0, hi = size - 1, mid = lo;
	int pSize = strlen(p);
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(str + sa[mid], p, pSize);
        if (res >= 0) hi = mid; // >= here!
        else lo = mid + 1;
    }

    if (strncmp(str + sa[lo], p, pSize) != 0) return pii(-1, -1); // sa[lo] here
    pii ans;
    ans.first = lo;
    lo = 0; hi = size - 1; mid = lo;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(str + sa[mid], p, pSize);
        if (res > 0) hi = mid;	// > here!
        else lo = mid + 1;
    }
    if (strncmp(str + sa[hi], p, pSize) != 0) hi--; // sa[hi] here
    ans.second = hi;
    return ans;
}

void build_lcp() {
	int lp = 0;
	F(i, size) {
		if (sai[i]) {
			int j = sa[sai[i] - 1];
			while (str[i + lp] == str[j + lp]) {
				++lp;
			}
			lcp[sai[i] - 1] = lp;
			if (lp) --lp;
		}
	}
	lcp[size - 1] = 0;
}

char p[MAXN];
int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
	
	int cas;
	cin >> cas;
	while (cas--) {
		scanf("%s", str);
		strcat(str, "$");
		size = strlen(str);
		
		suffix_array();
		build_lcp();
		// F(i, size) printf("lcp=%d %s\n", lcp[i], str + sa[i]);

		int mx = 0;
		for (int i = 1; i < size; i += 1) {
			if (lcp[i] > lcp[mx]) mx = i;
		}
		if (!lcp[mx]) puts("No repetitions found!");
		else {
			strncpy(p, str + sa[mx], lcp[mx]);
			p[lcp[mx]] = '\0';

			pii match = string_match(p);
			printf("%s %d\n", p, match.second - match.first + 1);
		}
	}
	return 0;
}