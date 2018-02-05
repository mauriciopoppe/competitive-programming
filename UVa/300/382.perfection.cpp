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
typedef long long LL;

char w[][15]={"","PERFECT","DEFICIENT","ABUNDANT"};
int r[60001];

int get(int x)
{
    int c=1;
    for(int i=2;i<x;i++)
       if(x%i==0)c+=i;
    //cout<<c<<endl;
    if(c==x)return 1;
    if(c<x)return 2;
    return 3;
}

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    int t;
    printf("PERFECTION OUTPUT\n");
    while(cin>>t && t)
    {
        if(t==1)printf("%5d  %s\n",1,"DEFICIENT");         
        else if(r[t])printf("%5d  %s\n",t,w[r[t]]);
        else
            printf("%5d  %s\n",t,w[r[t]=get(t)]);    
    }
    printf("END OF OUTPUT\n");
    return 0;
}
