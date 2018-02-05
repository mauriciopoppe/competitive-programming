#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 21
using namespace std;

vector<vector<int> > g;
int d[M],val[M];

int main()
{    
    int i,j,k,u,v,c,n,from,to,cc=1; 
    while(1)
    {
        c=1;    
        g.clear();
        g.resize(M);
        
        if(scanf("%d",&n)==EOF)break;
        do
        {
           for(i=0;i<n;i++)
           {
               scanf("%d",&to);
               g[c].push_back(to);
               g[to].push_back(c);            
           }
           ++c;
        }while(scanf("%d",&n) && c<20);
        printf("Test Set #%d\n",cc++);
        for(i=0;i<n;i++)
        {
             scanf("%d%d",&from,&to);
             memset(d,0,sizeof(d));
             memset(val,-1,sizeof(val));
             val[from]=0;
             d[from]=1;
             queue<int> q;
             q.push(from);
             
             while(!q.empty())
             {
                 u=q.front();
                 q.pop();
                 int len=g[u].size();
                 for(int j=0;j<len;j++)
                 {
                      v=g[u][j];
                      if(!d[v])
                      {
                          d[v]=1;
                          val[v]=val[u]+1;
                          if(v==to)goto end;
                          q.push(v);                                    
                      }   
                 }                                           
             }        
             end:
             printf("%2d to %2d:%2d\n",from,to,val[to]);                    
        }                     
        printf("\n");                
    }
    return 0;
}
