#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 10010
using namespace std;

int val[M],cc[M],temp[M];
vector<vector<int> > g;

int main()
{
    int t,stat,lines,n,u,v,len;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&stat,&lines);
        g.clear();
        g.resize(stat+2);
        
        
        int j;
        for(int i=0;i<lines;i++)
        {
            j=0;
            while(scanf("%d",&n) && n)
            {
                 temp[j++]=n;
                 cc[n]++;
            }
            for(int k=0;k<j-1;k++)
                g[temp[k]].push_back(temp[k+1]),g[temp[k+1]].push_back(temp[k]);
        }
        //print(stat);
        int s=0;
        int ans=1<<30;
        for(int i=1;i<=stat;i++)
        {
             if(cc[i]>1)
             {
                  queue<int> q;
                  memset(val,0,sizeof(val));
                  q.push(i);
                  val[i]=1;
                  while(!q.empty())
                  {
                       u=q.front(),len=g[u].size();
                       q.pop();
                       for(int k=0;k<len;k++)
                       {
                            v=g[u][k];
                            if(!val[v])
                            {
                                val[v]=val[u]+1;
                                q.push(v);       
                            }   
                       }
                  }
                  int x=0;
                  for(int k=1;k<=stat;k++)
                     if(cc[k]>1)x+=val[k]-1;
                  //printf("%d %d\n",i,x);
                  if(x<ans){ans=x;s=i;}       
             }   
        }
        printf("Krochanska is in: %d\n",s);
        memset(cc,0,4*(stat+1));
    }
    return 0;
}
