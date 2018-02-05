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
typedef unsigned long long LL;
#define M 10001
LL dp[2][130];
bool b[130];
string w,buf;
map<char,string> m;

void num()
{
     for(int i=65;i<130;i++)
       printf("%c ",(char)i);
    NL;     
     
}

void print(LL n)
{
     char z[256];
     int i=0;
     for(;n!=0 || i==0;i++,n/=10)
        z[i]='0'+(int)(n%10);
     while(i-->0)putchar(z[i]);
     NL;
}

int main()
{
    int cas,q,n,level;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d",&n);
         getchar();
         m.clear();
         memset(b,0,sizeof b);
         F(i,n)
         {
              getline(cin,w);
              m[w[0]]=string(w.begin()+3,w.end());
              for(string::iterator it=w.begin()+3;it!=w.end();it++)
                 b[(int)*it]=1;
         }       
         scanf("%d",&q);
         char c;
         while(q--)
         {
              cin>>w>>c>>level;
              if(!b[(int)c]){printf("0\n");continue;}
              memset(dp,0,sizeof dp);
              //ini
              TR(w,it)
                 dp[0][(int)*it]++;
              memcpy(dp[1],dp[0],sizeof dp[0]);
              //num();
              for(int i=1;i<=level;i++)
              {
                  TR(m,it)
                    dp[1][(int)it->first]=0;
                  
                  TR(m,it)
                  {
                      int x=(int) it->first;    
                      if(dp[0][x])    
                      {
                          for(string::iterator itx=it->second.begin();itx!=it->second.end();itx++)
                               dp[1][(int)*itx]+=dp[0][x];                 
                      }
                  }
                  ///print(0);
                  //print(1);
                  //SP;
                  memcpy(dp[0],dp[1],sizeof dp[1]);
              }
              print(dp[1][c]);
         }
    }
    return 0;
}
