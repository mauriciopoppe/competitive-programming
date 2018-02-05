#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 32
using namespace std;

vector<vector<int> > g;
bitset<M> d;
int val[M];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int x,n,con,query,size,w,len,v;
    map<string,int> m;
    string wa,wb;
    scanf("%d",&x);
    
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(int z=1;z<=x;z++)
    {
        printf("DATA SET  %d\n\n",z);    
        scanf("%d%d%d",&n,&con,&query); 
        m.clear();
        g.clear();
        g.resize(n+1);
        
        int j=1;
        for(int i=0;i<n;i++)
            cin>>wa,m[wa]=j++;    
        
        for(int i=0;i<con;i++)
        {
            cin>>wa>>wb;
            g[m[wa]].push_back(m[wb]);    
            g[m[wb]].push_back(m[wa]);
        }      
        
        for(int k=0;k<query;k++)
        {
            cin>>size>>wa>>wb;
            fill(val,val+M,-1);
            d.reset();
            queue<int> q;    
            q.push(m[wa]);
            d[q.front()]=1;
            val[q.front()]=0;
            
            while(!q.empty())
            {
                 w=q.front();
                 q.pop();
                 len=g[w].size();
                 for(int i=0;i<len;i++)
                 {
                      v=g[w][i];
                      if(!d[v])
                      {
                          q.push(v);
                          val[v]=val[w]+1;
                          d[v]=1;     
                      }   
                 }                       
            }
            
            int res=size*val[m[wb]]*100;
            if(res>=0)printf("$%d\n",res);
            else printf("NO SHIPMENT POSSIBLE\n");
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}

