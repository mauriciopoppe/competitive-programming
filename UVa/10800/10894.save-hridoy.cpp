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
char w[3200];
char hor[][65] = {"*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*",
                  "*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.",
                  "*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..",
                  "....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..",
                  "*****.*...*...*...*****...*...*.*..**.*****.***...*****...*.."};

char ver[][6] = {
"*****",
"*....",
"*****",
"....*",
"*****",
".....",
".***.",
"*...*",
"*****",
"*...*",
"*...*",
".....",
"*...*",
"*...*",
"*...*",
".*.*.",
"..*..",
".....",
"*****",
"*....",
"***..",
"*....",
"*****",
".....",
".....",
".....",
"*...*",
"*...*",
"*****",
"*...*",
"*...*",
".....",
"*****",
"*...*",
"*****",
"*.*..",
"*..**",
".....",
"*****",
"..*..",
"..*..",
"..*..",
"*****",
".....",
"***..",
"*..*.",
"*...*",
"*..*.",
"***..",
".....",
"*****",
"*...*",
"*...*",
"*...*",
"*****",
".....",
"*...*",
".*.*.",
"..*..",
"..*..",
"..*.."};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int mx = 61;
    int n;
    while(scanf("%d", &n) && n)
    {
        int c = -1;                      
        if(n > 0)
        {
            for(int i = 0; i < 5; ++i)
            { 
                for(int j = 0; j < mx; ++j)
                   for(int l = 0; l < n; ++l)
                      w[++c] = hor[i][j];
                w[++c] = '\0';
                c = -1;                    
                for(int k = 0; k < n ; k++)
                     printf("%s\n",w);
            }      
        }
        else
        {
            n = -n;
            for(int i = 0; i < mx; ++i)
            { 
                for(int j = 0; j < 5; ++j)
                   for(int l = 0; l < n; ++l)
                      w[++c] = ver[i][j];
                w[++c] = '\0';
                c = -1;                    
                for(int k = 0; k < n ; k++)
                     printf("%s\n",w);
            }      
        }
        NL;
        NL;
    }
    return 0;
}
