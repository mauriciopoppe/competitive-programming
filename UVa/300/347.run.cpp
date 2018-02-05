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
#define M 10000000
bool b[M],g[M];
bool t[10];
char w[10],ww[10];
//189
/*
bool test(int &x)
{
     sprintf(ww,"%d",x);
     memcpy(w,ww,sizeof ww);
     int k=strlen(ww);
     sort(ww,ww+k);
     for(int i=1;i<k;i++)
     {    if(ww[i]==ww[i-1])return false;}       
     return true;
}*/
bool test(int &i)
{
     memset(t,0,sizeof t);
     sprintf(w,"%d",i);
     char *p=w;
     for(;*p;p++)
     {   
         if(t[*p-'0'])return false;       
         t[*p-'0']=1;
     }   
     return true;  
}

bool check(int &n)
{
     int s=strlen(w);
     int j=0;
     memset(t,0,sizeof t);
     F(i,s)
     {
          //move
          if(t[w[j]-'0'])return false;
          t[w[j]-'0']=1;
          int move=w[j]-'0';
          j=(j+move)%s;
     }
     if(w[j]==w[0])return true;
     return false;
}

int ini(int &n)
{
     for(int i=n;i<M;i++)
     {
          if(b[i])
          { 
                if(g[i])return i;
                continue;  
          }
          else if(test(i) && check(i))
          {
                {g[i]=1;return i;}
          }
          b[i]=1;
     }
     return -1;
}

int main()
{
    int n,cas=1;
    memset(b,0,sizeof b);
    memset(g,0,sizeof g);
    while(scanf("%d",&n) && n)
    {
        //long start=clock();                 
        printf("Case %d: %d\n",cas++,ini(n));
        //printf(">>%ld\n",clock()-start);
    }
    return 0;
}
