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
#define MX 1440
int next[MX];
char w[MX];
int k;

int is_palindrome(char w[])
{
    int size = strlen(w);
    for(int i = 0, j = size - 1; i < j; ++i, --j)
       if(w[i] != w[j])
          return 0;
    return 1;
}

void init()
{
    k = 0;
    F(i, MX)
    {
        int hh = i / 60;
        int mm = i % 60;
        //printf("%d %d\n", hh, mm);
        if(hh == 0)
           sprintf(w, "%d", mm);
        else
           sprintf(w, "%d%02d", hh, mm);
        
        if(is_palindrome(w))
           next[k++] = i;
    }
    next[k++] = 0;
}

int main()
{
    init();
    int cas;
    scanf("%d", &cas);
    gets(w);
    while(cas--)
    {
        gets(w);
        int hh, mm;
        sscanf(w, "%d:%d", &hh, &mm);
        int total = hh * 60 + mm;
        int i;
        for(i = 0; i < k; ++i)
        {
            if(next[i] == total)
            {
               printf("%02d:%02d\n", next[i + 1] / 60, next[i + 1] % 60);
               break;
            }
            else if(next[i] > total)
            {
               printf("%02d:%02d\n", next[i] / 60, next[i] % 60);
               break;
            }            
        }
        if(i == k)
           printf("00:00\n");
    }    
    return 0;
}
