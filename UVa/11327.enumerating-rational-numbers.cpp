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

#define M 200000 + 10
int phi_cnt[M];
LL sum[M];

int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i += 1) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			result -= result / i;
		}
	}
	if (n > 1) {
		result -= result / n;
	}
	return result;
}

void precalc() {
	sum[1] = 2;
	phi_cnt[1] = 2;
	for (int i = 2; i < M; i += 1) {
		phi_cnt[i] = phi(i);
		sum[i] = sum[i - 1] + phi_cnt[i];
	}
	sum[M] = 15000000000LL;
}

int find_den(int n, int req) {
	for (int i = 1; i <= n; i += 1) {
		if (__gcd(n, i) == 1) {
			--req;
			if (!req) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	LL n;
	precalc();
	while (cin >> n && n) {
		if (n == 1) {
			puts("0/1");
			continue;
		}
		if (n == 2) {
			puts("1/1");
			continue;
		}

		int lo = 0, hi = M;
		while (hi - lo > 1) {
			int mid = lo + (hi - lo) / 2;
			// printf("%d %d %d\n", lo, hi, mid);
			if (sum[mid] < n) lo = mid;
			else hi = mid;
		}

		printf("%d/%d\n", find_den(lo + 1, n - sum[lo]), lo + 1);
	}

	return 0;
}