
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
#define min3(a,b,c) (min(min(a,b),min(b,c)))
typedef long long LL;

char w[1010];
int ed[1010][1010];
int editDistance()
{
    int val,i,j,ad=0,del=0;
    int s=strlen(w);
    int m,n;
    string a="",b="";
    if(s&1)
    {
         a=string(w,w+s/2);
         b=string(w+s/2+1,w+s);
    }
    else
    {
         a=string(w,w+s/2);
         b=string(w+s/2,w+s);
    }
    
    reverse(ALL(b));
    m=a.size();
    n=b.size();
    
    printf("[%s][%s] %d %d\n",a.c_str(),b.c_str(),m,n);
    
    for (i=0; i<=m; i++) ed[i][0] = i;     //deletion
    for (j=0; j<=n; j++) ed[0][j] = j;     //insertion
    
   for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
        {
            val = (a[i-1] == b[j-1]) ? 0 : 1;//1 for substitution
            ed[i][j] = min3(
                       ed[i-1][j-1] + val,   //substitution
                       ed[i-1][j]+1 ,        //deletion
                       ed[i][j-1]+1          //insertion
                       );
        }     
    printf("diff(a,b)=%d\n",ed[m][n]);
    return ed[m][n];
}

int main()
{
    int t;
    scanf("%d",&t);
    F(q,t)
    {
        scanf("%s",w);
        printf("Case %d: %d\n",q+1,editDistance());
    }
}
