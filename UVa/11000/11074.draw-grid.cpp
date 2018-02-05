#include<cstdio>
#include<cstdlib>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{
    int squares, wall, n;
    int cas = 1;
    while(scanf("%d%d%d", &squares, &wall ,&n) && squares)
    {
        printf("Case %d:\n",cas++);                  
        int total = (squares + wall) * n + wall;
        string del(total, '*');
        string dot(squares, '.');
        string wall_single(wall, '*');
        string line = wall_single;
        F(i, n)
           line += dot + wall_single;
           
        F(i, wall)
           printf("%s\n",del.c_str());
           
        F(i, n)
        {
            F(j, squares)
               printf("%s\n", line.c_str());
            F(j, wall)
               printf("%s\n", del.c_str()); 
        }
        
        NL;
    }
    return 0;
}
