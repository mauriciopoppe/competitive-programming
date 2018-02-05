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
int a[1001][26];
int b[26];
char w[500];
int main()
{
    int n=0;
    while(gets(w) && strcmp(w,"#"))
    {
         for(int i=0;w[i];i++)
            a[n][w[i]-'a']++;
         ++n;      
    }
    while(gets(w) && strcmp(w,"#"))
    {
         int c=0;
         memset(b,0,sizeof b);
         for(int i=0;w[i];i++)
            if(isalpha(w[i]))
               b[w[i]-'a']++;
         
         for(int i=0;i<n;i++)
         {                 
             int j=0;
             for(;j<26;j++)
                if(a[i][j]>b[j])break;
             if(j==26)c++;    
         }
         printf("%d\n",c);
    }
    return 0;
}
