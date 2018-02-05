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
int h[]={1,6,2,5,3,4};
int d[6];
void north()
{
    int a[6];
    a[0]=d[3];
    a[1]=d[2];
    a[2]=d[0];
    a[3]=d[1];
    a[4]=d[4];
    a[5]=d[5];
    F(i,6)d[i]=a[i];
}
void south()
{
    int a[6];
    a[0]=d[2];
    a[1]=d[3];
    a[2]=d[1];
    a[3]=d[0];
    a[4]=d[4];
    a[5]=d[5];
    F(i,6)d[i]=a[i];
}
//int h[]={1,6,2,5,3,4};
void east()
{
    int a[6];
    a[0]=d[4];
    a[1]=d[5];
    a[2]=d[2];
    a[3]=d[3];
    a[4]=d[1];
    a[5]=d[0];
    F(i,6)d[i]=a[i];
}
void west()
{
    int a[6];
    a[0]=d[5];
    a[1]=d[4];
    a[2]=d[2];
    a[3]=d[3];
    a[4]=d[0];
    a[5]=d[1];
    F(i,6)d[i]=a[i];
}
int main()
{
    int n;
    string w;
    while(scanf("%d",&n) && n)
    {
          F(i,6)d[i]=h[i];               
          F(i,n)
          {               
              cin>>w;
              if(w=="north")north();
              else if(w=="south")south();
              else if(w=="east")east();
              else west();
          }
          printf("%d\n",d[0]);
    }
    return 0;
}
