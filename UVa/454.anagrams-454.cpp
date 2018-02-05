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

struct p{
       string a,b;
       p(string x)
       {
            a=x;    
            char w[10000];    
            int j=0;
            TR(x,it)
                if(*it!=' ')w[j++]=*it;
            w[j]='\0';    
            b=string(w);
            sort(ALL(b));
       }
       bool operator<(const p &x)const
       {
            if(a!=x.a)return a<x.a;
            return b<x.b;     
       }
};

int main()
{
    char w[1000];
    string ori;
    int t,len;
    scanf("%d",&t);
    getchar();
    getchar();
    F(q,t)
    {
          if(q)NL;
          vector<p> v;
          while(getline(cin,ori) && (len=ori.size()))
               v.PB(p(ori));
          sort(ALL(v));
          int s=v.size();
          F(i,s)
            FOR(j,i+1,s)
            {
                if(v[i].b==v[j].b)printf("%s = %s\n",v[i].a.c_str(),v[j].a.c_str());
            }
    }
    return 0;
}
