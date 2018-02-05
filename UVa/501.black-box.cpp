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
int number[40000], query[40000];
int main()
{
    /*multiset<int> k;
    k.insert(3);
    multiset<int>::iterator it1 = k.begin();
    k.insert(1);
    printf("%d\n", *it1);
    k.insert(3);
    printf("%d\n", *it1);
    --it1;
    printf("%d\n", *it1);
    ++it1;
    printf("%d\n", *it1);
    ++it1;
    printf("%d\n", *it1);*/

    
    int cas;
    int n, q;
    scanf("%d", &cas);
    for(int z = 0; z < cas; ++ z)
    {
        scanf("%d%d", &n ,&q);
        for(int i = 0; i < n; ++i)
           scanf("%d", &number[i]);
        for(int i = 0; i < q; ++i)
           scanf("%d", &query[i]);
        
        //solve
        multiset<int> m;
        int j = 0;
        multiset<int>::iterator it = m.end();

        for(int i = 0; i < n && j < q; ++i)
        {
            m.insert(number[i]);
            if(it != m.end() && number[i] < *it)
               --it;
            while(j < q && query[j] == i + 1)
            {
                if(it == m.end())
                   it = m.begin();
                else
                   ++it;
                printf("%d\n", *it);
                ++j;
            }
            if(j == q)
               break;
        }
        NL;
    }
    return 0;
}
