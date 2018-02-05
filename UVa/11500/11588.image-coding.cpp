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
int v[27];
char m[100];
int row, col;
int main()
{
    int cas;
    int M, N;
    scanf("%d", &cas);
    F(z, cas)
    {
        scanf("%d%d%d%d", &row, &col, &M, &N);
        gets(m);
        memset(v, 0, sizeof v);
        for(int i = 0; i < row; ++i)
        {
           gets(m);
           for(int j = 0; j < col; ++j)
             v[m[j] - 'A']++;
        }
        int mx = -1;
        for(int i = 0; i < 26; ++i)
           mx = max(mx, v[i]);
        
        int total = 0;
        for(int i = 0; i < 26; ++i)
           if(v[i] == mx)
              total += v[i];
        printf("Case %d: %d\n", z + 1, total * M + (row * col - total) * N);
    }
    return 0;
}
