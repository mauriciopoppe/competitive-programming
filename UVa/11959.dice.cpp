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
//top, bottom, front, left, back, right.
char dice[10],d[10];
char a[10];

void rU()
{
     char a[7];
     a[0]=d[4];
     a[1]=d[2];
     a[2]=d[0];
     a[3]=d[3];
     a[4]=d[1];
     a[5]=d[5];
     F(i,6)d[i]=a[i];
} 

void rR()
{
     char a[7];
     a[0]=d[0];
     a[1]=d[1];
     a[2]=d[3];
     a[3]=d[4];
     a[4]=d[5];
     a[5]=d[2];
     F(i,6)d[i]=a[i];
} 

void rS()
{
     char a[7];
     a[0]=d[3];
     a[1]=d[5];
     a[2]=d[2];
     a[3]=d[1];
     a[4]=d[4];
     a[5]=d[0];
     F(i,6)d[i]=a[i];
} 

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
         scanf("%s %s",dice,d);
         bool f=0;
         F(i,4)
         {
             rU();
             F(j,4)
             {
                 rR();
                 F(k,4)
                 {
                     rS();
                     if(strcmp(d,dice)==0){f=1;goto end;}  
                 }  
             }  
         }
         end:
         if(f)printf("Equal\n");
         else printf("Not Equal\n");
    }
    return 0;
}
