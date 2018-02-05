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
char w[104];
char r[104];
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        scanf("%s",w);
        int s=strlen(w);
        int mx=s/n;
        r[mx]='\0';
        int j=0;
        F(i,s)
        {
             if(j<mx)r[mx-j-1]=w[i],j++;
             else printf("%s",r), j=0, r[mx-j-1]=w[i],j++; 
        }
        printf("%s\n",r);
    }
    return 0;
}
