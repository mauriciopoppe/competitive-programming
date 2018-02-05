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
int a[6],n,c;
bool check()
{
     for(int i=1;i<n;i++)
        if(a[i]<a[i-1])return false;
     return true;          
}

void bt()
{
     if(check())c++;
     else
        for(int i=1;i<n;i++)
            if(a[i]<a[i-1])
            {
                swap(a[i],a[i-1]);
                bt();
                swap(a[i],a[i-1]);                           
            }    
}

int main()
{
    int cas=1;
    while(scanf("%d",&n) && n)
    {
         F(i,n)
           scanf("%d",&a[i]);
         c=0;
         if(!check())bt();
         printf("There are %d swap maps for input data set %d.\n",c,cas++);
    }
    return 0;
}
