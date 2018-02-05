// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define long long LL
using namespace std;

int main ()
{
    int m, n, t;

    while ( scanf ("%d %d %d", &m, &n, &t) != EOF ) {
        int times [10000 + 10];
        memset (times, 0, sizeof (times));

        if ( m > n ) swap (m, n);

        times [m] = 1;
        times [n] = 1;

        for ( int i = m; i <= t; i++ ) {
            if ( times [i] ) {
                if ( i + m <= t ) times [i + m] = max ( times [i + m], times [i] + 1);
                if ( i + n <= t ) times [i + n] = max ( times [i + n], times [i] + 1);
            }
        }

        if ( times [t] > 0 ) printf ("%d\n", times [t]);
        else {
            bool printed = false;
            for ( int i = t - 1; i >= 0; i-- ) {
                if ( times [i] > 0 ) {
                    printf ("%d %d\n", times [i], t - i);
                    printed = true;
                    break;
                }
            }

            if ( !printed ) printf ("0 %d\n", t);
        }
    }

	return 0;
}

// @END_OF_SOURCE_CODE

