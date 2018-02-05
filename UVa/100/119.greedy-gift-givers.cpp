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
typedef long long LL;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,mo,to,cas=0;
    while(scanf("%d",&t)!=EOF)
    {
         if(cas)NL;
         cas=1;                
         map<string,int> money;
         vector<string> names;
         names.resize(t+1);
         string w,x;
         F(i,t){cin>>w; names[i]=w;}
         F(i,t)
         {
              cin>>w>>mo>>to;
              int split;
              if(to)split=mo/to,money[w]-=split*to;
              F(j,to)
              {
                  cin>>x;
                  money[x]+=split;
              }
         }
         //printf("here");
         F(i,t)
         { 
             printf("%s %d\n",names[i].c_str(),money[names[i]]);  
         }
    }
    return 0;
}
