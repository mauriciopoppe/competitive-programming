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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

vector<int> ord;
map<int,bool> check;
map<int,int> cc;

int main()
{
    int t;
    while(cin>>t)
    {
        if(!check[t])
           ord.PB(t),check[t]=1;
        cc[t]++;
    }
    int s=ord.size();
    F(i,s)
        printf("%d %d\n",ord[i],cc[ord[i]]);
    //system("pause");
    return 0;
}
