#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<sstream>
#define M 301
using namespace std;

vector<vector<int> > g;
int val[M],par[M],res[M];
bitset<M> d;

int main()
{
    int n,from,to,qq,u,v,len;
    string buf,w;
    while(scanf("%d",&n)!=EOF)
    {
         printf("-----\n");                     
         getchar();
         g.clear();
         g.resize(n+1);                     
         for(int i=1;i<=n;i++)
         {
             getline(cin,w);
             for(int j=0,len=w.size();j<len;j++)
                 if(!isdigit(w[j]))w[j]=' ';    
             
             stringstream ss(w);  
             ss>>buf;
             while(ss>>buf)
             {
                 to=atoi(buf.c_str());
                 g[i].push_back(to);          
             }                            
         }                   
         
         scanf("%d",&qq);
         for(int k=0;k<qq;k++)
         {
             scanf("%d%d",&from,&to);
             queue<int> q;
             d.reset();
             memset(val,-1,sizeof(val));
             memset(par,-1,sizeof(par));
             
             d[from]=1;
             val[from]=0;             
             q.push(from);
             while(!q.empty())
             {
                 u=q.front();
                 q.pop();
                 len=g[u].size();
                 for(int i=0;i<len;i++)
                 {
                      v=g[u][i];   
                      if(!d[v])
                      {
                           d[v]=1;
                           val[v]=val[u]+1;
                           par[v]=u;
                           if(v==to)goto end;
                           q.push(v);    
                      }   
                 }                                           
             } 
             end:  
             if(val[to]!=-1)
             {
                 int j=0; 
                 res[j++]=to;
                 while(par[to]!=-1)
                 {
                      res[j++]=par[to];
                      to=par[to];             
                 }       
                 //system("pause");

                 printf("%d",res[j-1]);
                 for(int i=j-2;i>=0;i--)
                     printf(" %d",res[i]);
                 printf("\n");
             }
             else printf("connection impossible\n");
         }
                                         
    }
    return 0;
}
