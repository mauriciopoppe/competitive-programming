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
#define M 100005
int t[M],m;
char a[M],b[M];

int kmp()
{
    t[0]=t[1]=0;
    for(int i=2;i<=m;++i)
      for(int j=t[i-1];;j=t[j])
      {
           if(b[j]==b[i-1]){t[i]=j+1;break;}
           if(j==0)t[i]=0;break;   
      }
    F(i,m+1)printf("%d ",t[i]);NL;
    
    for(int j=0,i=0;;)
    {
        if(i==m)return j;
        if(a[i]==b[j])++j,++i;
        else if(j>0)j=t[j];
        else ++i;
    }
    return -1;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(gets(a))
    {
         m=strlen(a);
         for(int i=m-1,j=0;i>=0;--i,++j)
            b[j]=a[i];        
         int j=m-kmp()-1;
         printf("%d\n",j);
         printf("%s",a);
         for(;j>=0;--j)
           putchar(a[j]);
           //printf("]");
         NL;
    }
    return 0;
}
/*
int main() {
  string s;
  while (cin >> s) {
    string s_rev(s.rbegin(), s.rend());
    KMP kmp(s_rev);
    int max_match = kmp.Match(s);
    cout << (s + s_rev.substr(max_match)) << endl;
  }
}*/
