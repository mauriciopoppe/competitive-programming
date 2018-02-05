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
int v[15],n,c;
int fv[15];
int getHash(string &w)
{
    int s=w.size(),c=0;
    F(i,s)
        c+=(w[i]-'a'+1)<<((s-i-1)*5);  
    return c;    
}

int f(int &i)
{
    return (c/v[i])%n;
}

int main()
{
    string w,buf;
    while(getline(cin,w))
    {
         stringstream ss(w);
         n=0;
         int mx=IMAX;
         while(ss>>buf)
         {
               v[n]=getHash(buf);
               if(v[n]<mx)mx=v[n];
               n++;
         }
         c=mx;

         while(1)
         {     
              F(i,n)fv[i]=f(i);
              int ng=0;
              int i,j;
              for(i=0;i<n-1;i++)
                for(j=i+1;j<n;j++)
                  if(fv[i]==fv[j]){ng=1;goto end;}
              end:
              if(ng)
                  c=min(((c/v[i])+1)*v[i],((c/v[j])+1)*v[j]);
              else break;              
         }
         printf("%s\n%d\n\n",w.c_str(),c);
    }
    return 0;
}
