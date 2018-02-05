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

int main()
{
    string w;
    int size;
    while(cin >> w)
    {
        size = w.size();      
        string t = w;
        deque<string> v;
        for(int i = 0; i < 11; ++i)
            v.push_back(w),
            next_permutation(w.begin(), w.end());
        for(int i = 0; i < 10; ++i)
            prev_permutation(t.begin(), t.end()),
            v.push_front(t);
        int mx = -1;
        int best = -1;
        for(int i = 0; i < 21; ++i)
        {
            int mn = 999999;
            for(int j = 1; j < size; ++j)
                mn = min(mn, abs(v[i][j - 1] - v[i][j]));
            if(mn > mx)
               mx = mn, best = i;
        }
        printf("%s%d\n", v[best].c_str(), mx);
    }
    return 0;
}
