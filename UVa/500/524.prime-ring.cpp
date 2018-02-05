#include <iostream>
using namespace std;

int n;
int a [20];
bool av [20];
int isP [42] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0,
                    1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
                    0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
                    1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                    1};

bool valid (int num, int in)
{
    if ( in == n - 1 ) {
        if (isP [a [in - 1] + num] && isP [num + 1])
            return true;
        return false;
    }
    return isP [a[in - 1]+num];
}

void bktk (int index)
{
    if ( index == n ) {
        printf ("%d", a [0]);
        for ( int i = 1; i < n; i++ )
            printf (" %d", a [i]);
        printf ("\n");
        return;
    }

    for ( int i = 2; i <= n; i++ ) {
        if ( av [i] ) {
            if ( valid (i, index) ) {
                av [i] = false;
                a [index] = i;
                bktk (index + 1);
                av[i] = true;
            }
        }
    }
}

int main ()
{
    int cases = 0;

    while ( scanf ("%d", &n) != EOF ) {
        a [0] = 1;

        printf ("Case %d:\n", ++cases);
        memset (av, true, sizeof (av));

        bktk (1);
        printf ("\n");
    }

    return 0;
}
