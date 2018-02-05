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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
#define NL printf("\n")
typedef long long LL;
int a[21];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,x;
    vector<int> v;
    int cas=1;
    while(cin>>n)
    {       
       cin>>x;
       F(i,20)cin>>a[i],--a[i];
       
       v.clear();
       v.resize(n);
       F(i,n)v[i]=i+1;
       
       for(int i=0;i<20 && v.size()>x;i++)
       {
         for(int j=a[i]; j<v.size() && v.size()>x;j+=a[i])
            v.erase(v.begin()+j,v.begin()+j+1);
       }
       
       printf("Selection #%d\n",cas++);
       if(!v.empty())printf("%d",v[0]);
       for(int i=1;i<v.size();i++)
           printf(" %d",v[i]);
       NL;NL;
    }
    return 0;
}
