#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1001
#define mp make_pair
using namespace std;

typedef pair<int,int> pp;
int g[M][M],dx[]={-1,0,0,1},dy[]={0,-1,1,0},row,col;
int val[M][M];
bool d[M][M];

bool check(int x, int y)
{
    if(x>=0 && y>=0 && x<row && y<col)return true;
    return false; 
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,sx,sy,x,y;
    char w[M+5];
    scanf("%d",&t);
    while(t--)
    {
        memset(g,0,sizeof(g));
        memset(d,0,sizeof(d));        
        memset(val,0,sizeof(val));
        
        scanf("%d%d",&row,&col);
        queue<pp> q;
        
        for(int i=0;i<row;i++)
        {
            scanf("%s",w);
            for(int j=0;j<col;j++)
            {
                if(w[j]=='#')g[i][j]=1;
                else if(w[j]=='J'){sx=i;sy=j;}
                else if(w[j]=='F')
                {
                     q.push(mp(i,j));
                     val[i][j]=1;                     
                }                   
            }    
        }
        
        //fire!!!
        while(!q.empty())
        {
             pp u=q.front();
             q.pop();
             for(int i=0;i<4;i++)
             {
                 x=u.first+dx[i];
                 y=u.second+dy[i];
                 if(check(x,y) && !val[x][y] && !g[x][y])
                 {
                     val[x][y]=val[u.first][u.second]+1;
                     q.push(mp(x,y));          
                 }
             }
        }
        
        //for(int i=0;i<row;i++)
        //{for(int j=0;j<col;j++)printf("%d ",val[i][j]);printf("\n");}
        
        int end=-1;
        //Joe
        
        val[sx][sy]=d[sx][sy]=1;
        q.push(mp(sx,sy));
        
        while(!q.empty())
        {
             pp u=q.front();
             q.pop();
             for(int i=0;i<4;i++)
             {
                 x=u.first+dx[i];
                 y=u.second+dy[i];
                 if(!check(x,y)){end=val[u.first][u.second];goto E;}
                 if(!g[x][y] && (val[u.first][u.second]+1<val[x][y] || !val[x][y]) && !d[x][y])
                 {
                     val[x][y]=val[u.first][u.second]+1;
                     d[x][y]=1;
                     q.push(mp(x,y));       
                 }
             }            
        }        
        E:
        if(end>-1)printf("%d\n",end);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
