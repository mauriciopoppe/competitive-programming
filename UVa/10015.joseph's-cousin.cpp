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
int gen[4250], k;
bitset<40000> b;

void init()
{
     k = 0;
     gen[k++] = 2;
     for(int i = 3; i * i < 40000; i += 2)
        if(!b[i])
           for(int j = i * i, s = 2 * i; j < 40000; j += s)
             b[j] = 1;
     //printf("here");
     for(int i = 3; i < 40000; i += 2)
        if(!b[i])
           gen[k++] = i;
}

int main()
{
    init();
    int n;
    while(scanf("%d", &n) && n)
    {
        int alive = n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
           v[i] = i + 1;
        
        int start = 0;
        int j = 0;
        while(alive > 1)
        {
            int next = (start + gen[j++] - 1) % alive;
            start = next;
            v.erase(v.begin() + next, v.begin() + next + 1);
            --alive;
        }
        printf("%d\n", v[0]);
    }
    return 0;
}
