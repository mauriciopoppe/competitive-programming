#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define trav(a,x) for (auto& a: x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {

    ll n;
    vector<int> dp(41, 0);
    dp[0] = 0;
    for (int i = 1; i <= 40; i += 1) {
        for (int j = 40; j - i >= 0; j--) {
            if (dp[j - i] || j - i == 0) {
                dp[j] = max(dp[j], dp[j - i] + 1);
            }
        }
    }
    while (cin >> n) {
        int total = 0;
        for (ll i = 2; i * i <= n; i += 1) {
            if (n % i) continue;
            int pf = 0;
            while (n % i == 0) {
                pf++;
                n /= i;
            }
            total += dp[pf];
        }
        if (n > 1) ++total;
        printf("%d\n", total);
    }

    return 0;
}

