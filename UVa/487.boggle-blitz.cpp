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
int n;
char b[30][30];
bool f[30][30];
char w[30];

set<string> m;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
    dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;   
}

void bt(int i, int j, int ind)
{
     w[ind] = b[i][j];     
     f[i][j] = 1;
     if(ind >= 2)
     {
         string st = string(w, w + ind + 1);
         m.insert(st);
     }
     for(int k = 0; k < 8; ++k)
     {
         int nx = i + dx[k], ny = j + dy[k];
         if(check(nx, ny) && b[nx][ny] > w[ind] && !f[nx][ny])
             bt(nx, ny, ind + 1);
     }
     f[i][j] = 0;
}

bool comp(const string &a, const string &b)
{
    int s1 = a.size(), s2 = b.size();
    if(s1 != s2) return s1 < s2;
    return a < b;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        gets(b[0]);
        for(int i = 0; i < n; ++i)
           gets(b[i]);
        memset(f, 0, sizeof f);
        m.clear();
        for(int i = 0; i < n; ++i)
           for(int j = 0; j < n; ++j) 
              bt(i, j, 0);

        vector<string> v(ALL(m));
        sort(ALL(v), comp);
        TR(v, it)
           printf("%s\n", it->c_str());
        if(cas)NL;
    }
    return 0;
}
