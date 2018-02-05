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
#define GREEN 0
#define BLACK 1
#define RED   2
#define BLUE  3
#define WHITE 4

#define NORTH 0

char g[M][M];
int d[M][M][4][5];
int row, col;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

struct node{
       int x, y, color, direction;
};
node par[M][M];

bool check(int x, int y)
{
     return x >= 0 && x < row && y >= 0 && y < col;     
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas = 0;
    while(scanf("%d%d", &row, &col))
    {
        if(row + col == 0)
           break;
           
        if(cas)NL;

        getchar();
        int sx = -1, sy = -1, ex = -1, ey = -1;
        for(int i = 0; i < row; ++i)
        {
            gets(g[i]);
            for(int j = 0; j < col; ++j)
                if(g[i][j] == 'S')
                   sx = i, sy = j, g[i][j] = '.';
                else if(g[i][j] == 'T')
                   ex = i, ey = j, g[i][j] = '.';            
        }                  
        
        for(int i = 0; i < row; ++i)
           for(int j = 0; j < col; ++j)
              for(int k = 0; k < 4; ++k)
                 for(int l = 0; l < 5; ++l)
                    d[i][j][k][l] = -1;
        
        queue<node> q;
        node s = {sx, sy, GREEN, NORTH};
        q.push(s);
        d[sx][sy][NORTH][GREEN] = 0;
        
        while(!q.empty())
        {
             node t = q.front();
             //printf("%d %d %d dir = %d\n", t.x, t.y, t.color, t.direction);
             //printf("par %d %d %d\n", par[t.x][t.y].x, par[t.x][t.y].y, par[t.x][t.y].direction);
             //printf("%d\n", d[t.x][t.y][t.direction][t.color]);
             //SP;
             
             int next_d = (t.direction + 1) % 4;
             int back_d = t.direction - 1;
             if(back_d < 0) back_d = 3;
             q.pop();             
             int color = (t.color + 1) % 5;
             for(int i = 0; i < 4; ++i)
             {
                 int newx = t.x + dx[i], newy = t.y + dy[i];
                 int td;
                 if(i == t.direction) td = 1;
                 else if(i == next_d || i == back_d) td = 2;
                 else td = 3;
                 //printf("%d %d %d\n", newx, newy, );
                      
                 if(check(newx, newy) && g[newx][newy] == '.' &&
                    (d[newx][newy][i][color] == -1 || 
                     d[newx][newy][i][color] > d[t.x][t.y][t.direction][t.color] + td))
                 {                         
                      d[newx][newy][i][color] = d[t.x][t.y][t.direction][t.color] + td;
                      node temp;
                      temp.x = newx, temp.y = newy, temp.color = color, temp.direction = i;
                      par[newx][newy].x = t.x;
                      par[newx][newy].y = t.y;
                      par[newx][newy].direction = t.direction;                      
                      q.push(temp);
                 }
             }
        }
        end:
        printf("Case #%d\n", ++cas);
        int mn = 999999999;
        for(int i = 0; i < 4; ++i)
           if(d[ex][ey][i][GREEN] != -1)
              mn = min(mn, d[ex][ey][i][GREEN]);
              
        if(mn != 999999999)
           printf("minimum time = %d sec\n", mn);
        else
           printf("destination not reachable\n");
    }
    return 0;
}
