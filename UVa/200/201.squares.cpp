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
#define M 30
int sx[M][M], sy[M][M];
int x[M][M], y[M][M];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n, m, row, col;
    char w[5];
    int cas = 0;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if(cas)
            printf("\n**********************************\n\n");
                      
        for(int i = 0; i <= n; ++i)
           for(int j = 0; j <= n; ++j)
              sx[i][j] = x[i][j] = sy[i][j] = y[i][j] = 0;
              
        for(int i = 0; i < m; ++i)
        {
           scanf("%s%d%d", w, &row, &col);
           row--, col--;
           if(w[0] == 'H')
               x[row][col + 1] = 1;
           else
               y[col + 1][row] = 1;
        }
        
        for(int i = 0; i < n; ++i)
           for(int j = 1; j < n; ++j)
              sx[i][j] = sx[i][j - 1] + x[i][j];
        
        for(int j = 0; j < n; ++j)
           for(int i = 1; i < n; ++i)
              sy[i][j] = sy[i - 1][j] + y[i][j];
              
        /*for(int i = 0; i < n; ++i){
           for(int j = 0; j < n; ++j)
              printf("%d ", sx[i][j]);NL;}
        NL;
        for(int i = 0; i < n; ++i){
           for(int j = 0; j < n; ++j)
              printf("%d ", sy[i][j]);NL;}*/
              
        map<int, int> m;
        for(int k = 1; k <= n; ++k)
           for(int i = 0; i <= n- k; ++i)
              for(int j = 0; j <= n - k; ++j)
                 if(sx[i][j + k] - sx[i][j] == k &&
                    sx[i + k][j + k] - sx[i + k][j] == k &&
                    sy[i + k][j] - sy[i][j] == k &&
                    sy[i + k][j + k] - sy[i][j + k] == k)
                       m[k]++;
        
        printf("Problem #%d\n\n", ++cas);
        if(!m.size())
            printf("No completed squares can be found.\n");
        else
        {
            TR(m, it)
                 printf("%d square (s) of size %d\n", it->second, it->first); 
        }
        
    }
    return 0;
}
