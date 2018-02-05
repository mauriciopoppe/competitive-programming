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
#define M 1000
char w[M],z[M],n[M];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    bool f=0;
    int ind,j;
    while(gets(w) && strcmp(w,"#"))
    {                           
          int s=strlen(w);
          if(!s){NL;continue;}
          int i=0,j=0;
          if(f)    
          {
               while(isspace(w[j]))j++;
               for(;w[j]!=' ';j++)
                 if(isalpha(w[j]))
                   n[ind++]=w[j];
               n[ind]='\0';
               printf("%s\n",n);
               f=0;
          }       
                 
          if(w[s-1]=='-')
          {  
             for(i=s-1;w[i]!=' ';i--);
             s=i+1;
             ind=0;
             for(++i;w[i];i++)
                if(isalpha(w[i]))
                   n[ind++]=w[i];
             n[ind]='\0';
             f=1;
          }
          
          for(i=j;i<s;i++)
            if(isalpha(w[i]) || isspace(w[i]))
               putchar(w[i]);
          printf("%s\n",z);
    }
    return 0;
}
