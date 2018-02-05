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
#define M 1000001
bool b[M + M], s[M + M], e[M + M];

int main()
{
    int n, m;
    int start, end, rep;
    bool f;
    while(scanf("%d%d", &n, &m))
    {
         for(int i = 0; i < M; ++i)
             b[i] = s[i] = e[i] = 0;
             
         f = 1;
         if(n == 0 && m == 0)
             break;
         for(int i = 0; i < n; ++i)
         {
             scanf("%d%d", &start, &end);
             if(!f)continue;
             
             if(b[start])
                if(!e[start])
                   f = 0;
             
             if(b[end])
                if(!s[end])
                   f = 0;
                   
             for(int j = start + 1; j < end && f; ++j)
             {
                 if(b[j])
                    f = 0;
                 b[j] = 1;
             }
             
             if(!b[end])
                e[end] = 1;
             if(!b[start])
                s[start] = 1;
                 
             b[start] = b[end] = 1;
                             
         }
         
         for(int i = 0; i < m; ++i)
         {
             scanf("%d%d%d", &start, &end, &rep);
             if(!f)continue;
             
             while(1)
             {             
                 if(start > M && end > M)
                    break;
                    
                 if(start < M && b[start])
                    if(!e[start])
                       f = 0;
                 
                 if(end < M && b[end])
                    if(!s[end])
                       f = 0;
                       
                 for(int j = start + 1; j < M && j < end && f; ++j)
                 {
                     if(b[j])
                        f = 0;
                     b[j] = 1;
                 }
                
                 if(!b[end])
                    e[end] = 1;
                 if(!b[start])
                    s[start] = 1;
             
                     
                 b[start] = b[end] = 1;
                 //e[end] = s[start] = 1;                
                 
                 start += rep;
                 end += rep;
                 
                 //printf("%d %d\n", start, end);
             }
         }
         
         if(f) 
            puts("NO CONFLICT");
         else
            puts("CONFLICT");
    }
    return 0;
}
