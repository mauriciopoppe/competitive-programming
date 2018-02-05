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

vector<int> v[10];
int main()
{
    //2
    F(i,100)
        if(((i%10)+(int)(i/10))*((i%10)+(int)(i/10))==i)v[2].push_back(i);
    //printf("here");
    //4    
    F(i,10000)
        if(((i%100)+(int)(i/100))*((i%100)+(int)(i/100))==i)v[4].push_back(i);
    //6
    F(i,1000000)
        if(((i%1000)+(int)(i/1000))*((i%1000)+(int)(i/1000))==i)v[6].push_back(i);
    //8    
    F(i,100000000)
        if(((i%10000)+(int)(i/10000))*((i%10000)+(int)(i/10000))==i)v[8].push_back(i);
    int n;
    while(cin>>n)
    {
         int s=v[n].size();
         F(i,s)
            printf("%0*d\n",n,v[n][i]);                     
    }
    return 0;
}
