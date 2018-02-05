#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1024
using namespace std;

vector<vector<int> > g;
double p[M][2],dd;
int val[M],x,y;

void print(int t)
{
     for(int i=0;i<t;i++)
     {
         printf("Node %d,%d:",i,g[i].size());
         for(int j=0;j<g[i].size();j++)
           printf(" %d",g[i][j]);
         printf("\n");    
     }
}

bool dist(int i,int j)
{
    return (((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1])) < dd);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char w[50];
    int v,m,j,len,f;
    while(scanf("%d%d",&v,&m))
    {
         if(v==0)break;                     
         dd=(double)(v*m*60.0); 
         dd*=dd;
         dd+=1e-9;
         
         g.clear();
         g.resize(M);
         j=0;
         while(gets(w))
         {
             if(sscanf(w,"%lf %lf",&p[j][0],&p[j][1])==2)
             {
                 for(int i=j-1;i>=0;i--)          
                 {
                      if(dist(j,i))
                      {   
                          g[i].push_back(j);                
                          g[j].push_back(i);
                      }
                 }
                 ++j;
             }
             else if(j>=2)break;
         }
         
         //print(j);
             memset(val,0,sizeof(val));
             queue<int> q;
             q.push(0);
             val[0]=1;
             
             while(!q.empty())
             {
                   x=q.front();
                   q.pop();
                   len=g[x].size();
                   for(int k=0;k<len;k++)
                   {
                       y=g[x][k];
                       if(!val[y])    
                       {
                           val[y]=val[x]+1;                           
                           q.push(y);         
                       }
                   }
                   if(val[1]!=0)break;           
             }
             end:
             if(val[1]-2>=0)printf("Yes, visiting %d other holes.\n",val[1]-2);
             else printf("No.\n");
    }
    return 0;
}
