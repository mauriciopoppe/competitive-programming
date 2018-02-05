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
#define M 70000

int lis[M];
int bp[M];
int sister[M];

int LIS(int *a, int &size) {
    int lis_size;
    int i;
 
    //take the first element as the current LIS
    lis[0] = a[0];
    lis_size = 1;
 
    for(i = 1; i < size; ++i) {
        int pos = upper_bound(lis, lis + lis_size, a[i]) - lis;
 		if(pos == lis_size)                
           lis[lis_size++] = a[i];
        //the element is a candidate so store it in the LIS
        //the LIS size IS NOT affected
        else
           lis[pos] = a[i];
    }
    //return the number of elements in the LIS
    return lis_size;
}
int main() {
	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);

	int t, n, b, s;
	int k;
	cin >> t;
	F(z, t) {
		cin >> n >> b >> s;
		MS(bp, -1);
		F(i, b + 1) {
			cin >> k;
			bp[k] = i;
		}
		int size = 0;
		F(i, s + 1) {
			cin >> k;
			if (bp[k] != -1) sister[size++] = bp[k];
		}
		// F(i, 20) printf("%d ", bp[i]); NL;
		// F(i, size) printf("%d ", sister[i]); NL;
		printf("Case %d: %d\n", z + 1, LIS(sister, size));
	}
	return 0;
}