/*
 * 2051 Cell Phone.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: mauricio
 */

#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;
using namespace std;

const double pi = acos( -1.0 );

int n;
double r;
int x[2000], y[2000];

typedef pair<double, int> par;

vector<par> E;

int sweep( int i ) {

   E.clear();
   for( int j = 0; j < n; ++j ) {
      if( i == j ) continue;

      int dx = x[j] - x[i];
      int dy = y[j] - y[i];

      if( dx*dx + dy*dy > 2*r*2*r ) continue;

      double d = sqrt( (double)dx*dx + (double)dy*dy );
      double alfa = atan2( (double)dy, (double)dx );
      double beta = acos( d / (2*r) );

      E.push_back( par( alfa - beta, 0 ) );
      E.push_back( par( alfa + beta, 1 ) );
      E.push_back( par( alfa - beta + 2*pi, 0 ) );
      E.push_back( par( alfa + beta + 2*pi, 1 ) );
   }

   sort( E.begin(), E.end() );

   int curr = 1;
   int ret = 1;

   for( vector<par>::iterator it = E.begin(); it != E.end(); ++it ) {
      if( it->second == 0 ) curr += 1;
      else curr -= 1;
      ret = max(curr, ret);
   }

   return ret;
}

int main() {
   while( scanf( "%d%lf", &n, &r ) == 2 ) {
      if( n == 0 && r == 0 ) break;

      r += 0.00001;

      for( int i = 0; i < n; ++i )
         scanf( "%d%d", &x[i], &y[i] );

      int ret = 1;

      for( int i = 0; i < n; ++i )
         ret = max(sweep( i ), ret);

      printf( "It is possible to cover %d points.\n", ret );
   }

   return 0;
}


