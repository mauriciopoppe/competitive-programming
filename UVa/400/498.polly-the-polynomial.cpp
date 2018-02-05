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
int v[1000000];
int main()
{
    string a,b,buf;
    while(getline(cin,a) && getline(cin,b))
    {
         int j=0;
         stringstream sa(a);
         while(sa>>buf)v[j++]=atoi(buf.c_str());
         
         stringstream sb(b);
         int f=0;
         while(sb>>buf)
         {
              if(f)printf(" ");
              f=1;         
              int num=atoi(buf.c_str());
              int pw=1;
              
              int t=0;
              for(int i=j-1;i>=0;i--)
                  t+=v[i]*pw,pw*=num;
              printf("%d",t);                       
         }
         NL;
    }
    return 0;
}
