#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long x,y;
}point;

int compareAngles( const void *p1, const void *p2 );

int main()
{
    int nCases,c,k,i;
    long n;

    scanf( "%d", &nCases );
    while( nCases-- ) {

        point list [100001];
        point up [100001];
        point down [100001];

        scanf( "%lld", &n );
        for( c=0;n>0;n-- ) {
            long tempX,tempY;
            char tempChar;
            scanf( "%lld%lld%c", &tempX, &tempY, &tempChar );
            if( tempChar=='Y' ){
                list[c].x=tempX;
                list[c].y=tempY;
                c++;
            }
        }
        qsort( list, c, sizeof(point), compareAngles );

        int u = 0, d = 0;
        for ( k = 1; k < c; k++) {
            if (list[k].y <= list[0].y) {
                down[d++] = list[k];
            } else {
                up[u++] = list[k];
            }
        }

        printf("%d\n",c);
        printf("%lld %lld\n", list[0].x, list[0].y );
        for( i=0;i<d;i++ )
            printf( "%lld %lld\n", down[i].x, down[i].y );
        for( i=u-1;i>=0;i-- )
            printf( "%lld %lld\n", up[i].x, up[i].y );
    }
 return 0;
}
int compareAngles( const void *p1, const void *p2 )
{
    point *p11 = (point*) p1;
    point *p22 = (point*) p2;

    return ( p11->x != p22->x ) ? ( p11->x - p22->x ) : ( p11->y - p22->y );
}

