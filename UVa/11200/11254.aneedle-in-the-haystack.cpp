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
string n,m;
int sn,sm,*b;
bool f=0;
void buildKMP()
{
     int i=0,j=-1;
     b[i]=j;
     while(i<sm)
     {
          while(j>=0 && m[j]!=m[i])j=b[j];
          ++i,++j;
          b[i]=j;     
     }
}

void searchKMP()
{
     int i=0,j=0;
     while(i<sn)
     {
          while(j>=0 && m[j]!=n[i])j=b[j];
          ++i,++j;
          if(j==sm)
             f=1,printf("%d\n",i-sm),j=b[j]; 
     }     
}

int main()
{
    int cas=0;
    while(scanf("%d",&sm)!=EOF)
    {
         if(cas)NL;
         cas=1;                    
         getchar();
         cin>>m>>n;
         sn=n.size();
         f=0;
         if(sn<sm){NL;continue;}
         
         b=new int[sm+1];
         buildKMP();
         searchKMP();
         if(!f)NL;
    }
    return 0;
}
