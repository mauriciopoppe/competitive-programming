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
int a[101][101];
int row[101],col[101];
int main()
{
    int n;
    while(cin>>n && n)
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        F(i,n) 
          F(j,n)
            scanf("%d",&a[i][j]),row[i]+=a[i][j],col[j]+=a[i][j];
        
        int c1=0,c2=0,x=0,y=0;
        F(i,n)
        { 
              if(row[i]&1)c1++,x=i;
              if(col[i]&1)c2++,y=i;
        }
        
        if(!c1 && !c2)printf("OK\n");
        else if(c1==1 && c2==1)printf("Change bit (%d,%d)\n",x+1,y+1);
        else printf("Corrupt\n");
        
                         
    }
    return 0;
}
