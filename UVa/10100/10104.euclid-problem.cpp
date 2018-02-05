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

/**
 * Computes the values `x` and `y` for the equation
 *
 *    ax + by = gcd(a, b)
 *
 * Given that `a` and `b` are positive integers
 *
 * @param {int} a
 * @param {int} b
 * @param {int} x
 * @param {int} y
 * @returns {int} gcd(a, b)
 */
int extended_euclidean(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int gcd = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - a / b * y1;
  return gcd;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
    int x, y;
    int gcd = extended_euclidean(a, b, x, y);
    printf("%d %d %d\n", x, y, gcd);
	}
	return 0;
}