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
char w[1000];
int main()
{
    int cas,size;
    char *ptr;
    scanf("%d",&cas);
    getchar();
    getchar();
    F(z,cas)
    {
        if(z)NL;
        printf("Case #%d:\n",z+1);    
        while(gets(w) && (size = strlen(w)))
        {
            int c = 0;
            ptr = strtok(w, " ");
            while(ptr)
            {
                size = strlen(ptr);
                if(c < size)
                    putchar(ptr[c++]);
                ptr = strtok(NULL, " ");
            }            
            NL;
        }           
    }
    return 0;
}
