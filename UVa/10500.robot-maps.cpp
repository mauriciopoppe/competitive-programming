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
#define M 15
bool dis[M][M];
bool seen[M][M];
char graph[M][M];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int row, col;
int cnt;
bool check(int x, int y)
{
     return x >=0 && x < row && y >= 0 && y < col;
}

void dfs(int x, int y)
{
     dis[x][y] = seen[x][y] = 1;
     F(i, 4)
     {
        int sx = x + dx[i], sy = y + dy[i];
        if(check(sx, sy))
           seen[sx][sy] = 1;
     }
     
     F(i, 4)
     {
        int sx = x + dx[i], sy = y + dy[i];
        if(check(sx, sy))
        {
             if(!dis[sx][sy] && graph[sx][sy] == '0')
             {
                ++cnt;
                dfs(sx, sy);                             
                break;
             }
        }   
     }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char w[500];
    int sx, sy;
    while(scanf("%d %d",&row, &col) && row)
    {
         scanf("%d %d", &sx, &sy);
         getchar();
         F(i, row)
         {
            gets(w);
            int k = 0;  
            for(int j = 0; w[j]; ++j)
               if(w[j] != ' ')
                 graph[i][k++] = w[j];
         }
         memset(dis, 0, sizeof dis);
         memset(seen, 0, sizeof seen);
         cnt = 0;
         sx--;
         sy--;
         graph[sx][sy] = '0';
         dfs(sx, sy);
         string sep = "|";
         for(int i = 0; i < col; ++i)
            sep += "---|";
         
         //print
         printf("\n%s\n",sep.c_str());
         F(i, row)
         {
              printf("|");
              F(j, col)
                if(seen[i][j])
                  printf(" %c |", graph[i][j]);
                else printf(" ? |");
              NL;
         printf("%s\n",sep.c_str());              
         }
         printf("\nNUMBER OF MOVEMENTS: %d\n", cnt);                    
    }
    return 0;
}
