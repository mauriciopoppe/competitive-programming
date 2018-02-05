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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
#define EP 1e-5
typedef long long LL;

struct point{
       int x,y;
       };

int v[101][2];

int cross_product(point &origin, point &a, point &b)
{
    return (a.x-origin.x)*(b.y-origin.y)-(a.y-origin.y)*(b.x-origin.x); 
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string w;
    int t,n;
    int a,a1,b,b1;
    scanf("%d",&t);
    F(cas,t)
    {
         map<string,bool> m;
         scanf("%d",&n);
         getchar();
         int s=0;
         F(i,n)
         {
               getline(cin,w);
               if(m[w])continue;
               //printf("[%s]\n",w.c_str());
               m[w]=1;
               sscanf(w.c_str(),"%d.%d %d.%d",&a,&a1,&b,&b1);
               //printf("%d %d %d %d\n",a,a1,b,b1);
               v[s][0]=a*100+a1;
               v[s++][1]=b*100+b1;
         }
         
         //F(i,s)printf("%lf %lf\n",v[i][0],v[i][1]);
         
         point x,y,z;
         int mx=1;
         F(i,s-1)
         {
           x.x=v[i][0];
           x.y=v[i][1];      
           FOR(j,i+1,s)
           {
                y.x=v[j][0];
                y.y=v[j][1];       
                int c=0;
                F(k,s)
                {
                     z.x=v[k][0];
                     z.y=v[k][1]; 
                     if(cross_product(x,y,z)==0)++c;
                }
                if(c>mx)mx=c;
           }
        }
        if(mx==1)printf("Data set #%d contains a single gnu.\n",cas+1);   
        else printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n",cas+1,s,mx);
    }
    return 0;
}
