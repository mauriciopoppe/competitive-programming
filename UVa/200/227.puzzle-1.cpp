// http://uva.onlinejudge.org/external/2/227.html

#include <stdio.h>
#include <string.h>

int main ()
{
    freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);

    int cases = 0;
    bool line = false;
    char initial [5] [7];

    while ( gets (initial [0]) ) {

        if ( strcmp (initial [0], "Z") == 0 )
            return 0;

        gets (initial [1]);
        gets (initial [2]);
        gets (initial [3]);
        gets (initial [4]);

        int blank_x;
        int blank_y;

        for ( int i = 0; i < 5; i++ ) {
            for ( int j = 0; j < 5; j++ ) {
                if ( initial [i] [j] == ' ' ) {
                    blank_x = i;
                    blank_y = j;
                    i = j = 5;
                }
            }
        }

        char command [1000];
        bool valid = true;
        bool exit_koro = false;

        while ( !exit_koro && gets (command)) {

            for ( int i = 0; command [i] != 0; i++ ) {

                if ( command [i] == '0' || !valid ) {
                    exit_koro = true;
                    break;
                }

                switch (command [i]) {
                    case 'A' :
                        if ( blank_x == 0 )
                            valid = false;
                        else {
                            initial [blank_x] [blank_y] = initial [blank_x - 1] [blank_y];
                            initial [blank_x - 1] [blank_y] = ' ';
                            blank_x--;
                        }
                    break;

                    case 'B' :
                        if ( blank_x == 4 )
                            valid = false;
                        else {
                            initial [blank_x] [blank_y] = initial [blank_x + 1] [blank_y];
                            initial [blank_x + 1] [blank_y] = ' ';
                            blank_x++;
                        }
                    break;

                    case 'R' :
                        if ( blank_y == 4 )
                            valid = false;
                        else {
                            initial [blank_x] [blank_y] = initial [blank_x] [blank_y + 1];
                            initial [blank_x] [blank_y + 1] = ' ';
                            blank_y++;
                        }
                    break;

                    case 'L' :
                        if ( blank_y == 0 )
                            valid = false;
                        else {
                            initial [blank_x] [blank_y] = initial [blank_x] [blank_y - 1];
                            initial [blank_x] [blank_y - 1] = ' ';
                            blank_y--;
                        }
                    break;
                }
            }
        }

        if ( line )
            printf ("\n");
        line = true;

        printf ("Puzzle #%d:\n", ++cases);

        if ( valid ) {
            for ( int i = 0; i < 5; i++ ) {
                printf ("%c %c %c %c %c\n", initial [i] [0], initial [i] [1],
                initial [i] [2], initial [i] [3], initial [i] [4]);
            }
        }

        else
            printf ("This puzzle has no final configuration.\n");

    }

    return 0;
}
