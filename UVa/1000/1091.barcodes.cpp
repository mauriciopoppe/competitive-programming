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
#define M 205
int limit[M];
int v[M];
int n, size;
map<string, int> m;
vector<string> w;
int valid()
{
    for(int i = 1; i <= 100; ++i)
    {
       int j;
       int up = i * 2;
       for(j = 0; j < n; ++j)
           if(v[j] >= i - limit[i] && v[j] <= i + limit[i])
              continue;
           else if(v[j] >= up - limit[up] && v[j] <= up + limit[up])
              continue;
           else
              break;
       if(j == n)
       {
           for(j = 0; j < n; ++j)
               if(v[j] >= i - limit[i] && v[j] <= i + limit[i])
                  v[j] = 0;
               else if(v[j] >= up - limit[up] && v[j] <= up + limit[up])
                  v[j] = 1;            
           return i;
       }
    }
    return 0;
}

int check_valid_codes()
{
    for(int i = 1; i < size - 1; ++i)
    {
       int k = m[w[i]];     
       if(!k || k == 100)
          return 0;
    }
    return m[w[0]] == 100 && m[w[size - 1]] == 100;
}

int check_start()
{
    //puts("it's valid");
    //for(int i = 0; i < n; ++i)
     //  printf("%d ", v[i]);NL;
    
    for(int i = 5; i < n; i += 6)
       if(v[i])
          return 0;
    w.clear();
    for(int i = 0; i < n; i += 6)
    {
       stringstream ss;     
       for(int j = i; j < i + 5; ++j)
          ss << v[j];
       w.push_back(ss.str());
    }
    
    //normal sweep
    size = w.size();
    if(check_valid_codes())
       return 1;
    
    //reverse
    for(int i = 0; i < size; ++i)
       reverse(w[i].begin(), w[i].end());
    reverse(w.begin(), w.end());
    if(check_valid_codes())
       return 1;
    return 0;
}

int check_c()
{
    int k = 0;
    //printf("%d\n", size - 4);
    for(int i = 1; i < size - 3; ++i)
       k += ((size - 4 - i) % 10 + 1) * m[w[i]];
    k %= 11;
    //printf("c = %d\n", k);
    return k == m[w[size - 3]];
}

int check_k()
{
    int k = 0;
    for(int i = 1; i < size - 2; ++i)
       k += ((size - 3 - i) % 9 + 1) * m[w[i]];
    k %= 11;
    //printf("k = %d\n", k);
    return k == m[w[size - 2]];
}

void solve()
{
     if(n < 29 || n % 6 != 5 || !valid() || !check_start())
        puts("bad code");
     else if(!check_c())
        puts("bad C");
     else if(!check_k())
        puts("bad K");
     else
     {
        for(int i = 1; i < size - 3; ++i)
        {
           int k = m[w[i]];
           if(k != 10)
              printf("%d", k);
           else
              putchar('-');                  
        }
        NL;
     }     
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    //init
    for(int i = 0, k = 0; i < M; i += 20, ++k)
       for(int j = i; j < i + 20; ++j)
          limit[j] = k;
    m["00001"] = 0;      
    m["10001"] = 1;
    m["01001"] = 2;
    m["11000"] = 3;
    m["00101"] = 4;
    m["10100"] = 5;
    m["01100"] = 6;
    m["00011"] = 7;
    m["10010"] = 8;
    m["10000"] = 9;
    m["00100"] = 10;
    m["00110"] = 100;
          
    int cas = 1;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; ++i)              
           scanf("%d", &v[i]);
        printf("Case %d: ", cas++);
        solve();
    }
    return 0;
}
