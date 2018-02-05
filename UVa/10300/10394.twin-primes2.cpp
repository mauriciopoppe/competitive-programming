// http://uva.onlinejudge.org/external/103/10394.html

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
#include <bitset>
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 20000000
using namespace std;

bool mark [N];
vector <int> primeList;

void sieve ()
{
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for ( int i = 4; i < N; i += 2 )
        mark [i] = false;

    for ( int i = 3; i * i <= N; i++ ) {
        if ( mark [i] ) {
            for ( int j = i * i; j < N; j += 2 * i )
                mark [j] = false;
        }
    }

    primeList.clear ();
    primeList.push_back (2);

    for ( int i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            primeList.push_back (i);
    }

    //printf ("%d\n", primeList.size ());
}

int main ()
{
    sieve ();

    vector <int> twinPrime;

    for ( size_t i = 1; i < primeList.size (); i++ ) {
        if ( primeList [i] - primeList [i - 1] == 2 )
            twinPrime.push_back (primeList [i - 1]);
    }

    int s;

    while ( scanf ("%d", &s) != EOF ) {
        printf ("(%d, %d)\n", twinPrime [s - 1], twinPrime [s - 1] + 2);
    }

    return 0;
}

// @END_OF_SOURCE_CODE
