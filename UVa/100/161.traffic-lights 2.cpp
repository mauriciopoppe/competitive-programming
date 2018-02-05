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
#define M 18001
int b[M];
int num[M];
int k;

void print(int z)
{
    for(int i = 0; i <= z; ++i)
       printf("%2d ", i);NL; 
    for(int i = 0; i <= z; ++i)
       printf("%2d ", b[i]);NL;
}

void solve()
{
    memset(b, 0, sizeof b);
    
    //next lights    
    for(int i = 0; i < k; ++i)    
        for(int j = 0; j < M; j += 2 * num[i])
             for(int z = j; z < j + num[i] - 5 && z < M; ++z)
                b[z] += 1;
    //SP;
    //find min
    int mn = 0;
    for(int i = 1; i < k; ++i)
       if(num[i] < num[mn])
          mn = i;
    
    for(int i = num[mn] * 2; i < M; ++i)
       if(b[i] == k)
       {
           printf("%02d:%02d:%02d\n", i / 3600, (i / 60) % 60, i % 60);
           return;
       }
    printf("Signals fail to synchronise in 5 hours\n");
}

int main()
{
    while(1)
    {
       k = 2;
       scanf("%d%d", &num[0], &num[1]);
       while(scanf("%d", &num[k]) && num[k])
          ++k;
       
       if(k == 2 && num[0] == num[1] && num[1] == num[2] && num[2] == 0)
           break;
       //puts("here");    
       solve();
    }
    return 0;
}
