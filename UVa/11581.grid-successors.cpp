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

bool checked[1025];
char w[5][5], t[5][5];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int mark_matrix()
{
     int k = 0;
     for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
           k |= (w[i][j] - '0') << (i * 3 + j);
     if(checked[k])
        return 1;
     checked[k] = 1;
     return 2;
}

int solve()
{
    memset(checked, 0, sizeof checked);
    mark_matrix();
    for(int z = 0; z < 1 << 10; ++z)
    {
        memset(t, 0, sizeof t);    
        for(int i = 0; i < 3; ++i)
           for(int j = 0; j < 3; ++j)
               for(int k = 0; k < 4; ++k)    
               {
                   int nx = i + dx[k], ny = j + dy[k];
                   if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
                      t[i][j] += (w[nx][ny] - '0');
                   t[i][j] &= 1;
               }
        for(int i = 0; i < 3; ++i)
           for(int j = 0; j < 3; ++j)
              w[i][j] = t[i][j] + '0';
        if(mark_matrix() == 1)
           return z - 1;
    }
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        for(int i = 0; i < 3; ++i)
           scanf("%s", w[i]);
        
        printf("%d\n", solve());
    }
    return 0;
}
