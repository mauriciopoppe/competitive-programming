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
#define M 780
struct node{
       int sum, x;
       bool operator<(const node& a)const
       {
            return a.sum<sum;
       }
};
int a[M],b[M],c[M],pos[M];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
/*
3
9 6 4
3 6 1243132
4 1432143 1324*/
    int n,k,x,y,s;
    node p,t;
    while(scanf("%d",&n)!=EOF)
    {
         F(i,n)scanf("%d",&a[i]);
         sort(a,a+n);
         a[n]=b[n]=c[n]=1000000000;
         //F(i,n)printf("%d ",a[i]);NL;
         for(int i=1;i<n;i++)
         {
              F(j,n)scanf("%d",&b[j]);
              sort(b,b+n);
              priority_queue<node> q;
              F(j,n)
                    p.sum=a[j]+b[0],p.x=j,pos[j]=1,q.push(p);
              
              F(j,n)
                    p=q.top(), c[j]=p.sum, q.pop(), 
                    p.sum=a[p.x] + b[pos[p.x]++], q.push(p);
              //sort(c,c+n);
              F(j,n)a[j]=c[j];
              //F(j,n)printf("%d ",c[j]);NL;
         }
         printf("%d",a[0]);
         for(int i = 1; i < n; ++i)
               printf(" %d",a[i]);
         NL;
    }
    return 0;
}
/*
1 3 7 9 9
1 2 3 9 9
*/
