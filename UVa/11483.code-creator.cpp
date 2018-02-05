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

char w[5000];

void get(char *s)
{
     while(gets(s))
     {
         if(s[0] == '\0')
             continue;
         return;               
     }     
}

bool check(char w)
{
     return w == '\'' || w == '\\' || w == '\"';          
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    int cas = 1;
    while(scanf("%d",&n) && n)
    {
        getchar();                 
        printf("Case %d:\n",cas++);
        printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
        F(i, n)
        {
            printf("printf(\"");
            get(w);
            for(int i = 0; w[i]; ++i)
            {
                if(check(w[i]))
                   printf("\\");
                putchar(w[i]);
            } 
            printf("\\n\");\n");
        }                
        printf("printf(\"\\n\");\nreturn 0;\n}\n");
    }
    return 0;
}
