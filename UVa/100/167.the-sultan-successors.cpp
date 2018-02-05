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
typedef long long LL;
int n=8,ind=0;
int m[100][8];
int num[8][8];

int cand(int a[], int c[], int k)
{
    int i=0,j=0,candidates=0;
    for(;i<n;i++)
    {
          for(j=0;j<k;j++)
             if(abs(j-k)==abs(i-a[j]) || i==a[j])break;
          if(j==k)c[candidates++]=i;       
    }    
    return candidates;
}

void bt(int a[], int k)
{
     if(k==n)
     {
          F(i,8)m[ind][i]=a[i];
          ind++;   
     }     
     else
     {
          int c[9];
          int nc=cand(a,c,k);
          for(int i=0;i<nc;i++)
          {
              a[k]=c[i];
              bt(a,k+1);    
          }
     }
}

int main()
{   
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int a[9];
    bt(a,0);
    int t;
    scanf("%d",&t);
    while(t--)
    {
         int mx=0;
         F(i,8)
           F(j,8)
             scanf("%d",&num[i][j]);
         
         F(i,100)
         {
             int t=0;
             F(j,8)t+=num[j][m[i][j]];
             if(t>mx)mx=t;    
         }
         printf("%5d\n",mx);
    }
    return 0;
}
