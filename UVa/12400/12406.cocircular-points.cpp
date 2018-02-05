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
#define pow2(a) ((a)*(a))
typedef long long LL;

int p[101][2];
double v[3];
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {                         
         F(i,n)scanf("%d%d",&p[i][0],&p[i][1]);
         if(n==1 || n==2){printf("%d\n",n);continue;}
         
         int mx=2;
         for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
            {
                 double x=(p[i][0]+p[j][0])/2.0;
                 double y=(p[i][1]+p[j][1])/2.0;
                 double d=pow2(p[i][0]-x)+pow2(p[i][1]-y);
                 v[0]=x;
                 v[1]=y;
                 v[2]=d;
                 //F(i,3)printf("%lf ",v[i]);NL;SP;
                 int c=0; 
                 for(int k=0;k<n;k++)
                    if(pow2(p[k][0]-v[0])+pow2(p[k][1]-v[1])-v[2]==0)++c;
                 if(c>mx)mx=c;                 
            }                 
         printf("%d\n",mx);    
    }
    return 0;
}
