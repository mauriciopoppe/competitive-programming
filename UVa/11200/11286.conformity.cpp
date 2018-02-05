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
#define M 10002
bool b[M];
int v[M][5];
int main()
{
    int students;
    while(scanf("%d", &students) && students)
    {
        map<string, int> m;
        vector<string> name(students);
        memset(b, 0, sizeof b);
        for(int i = 0; i < students; ++i)
        {
            for(int j = 0; j < 5; ++j)    
               scanf("%d", &v[i][j]);
            sort(v[i], v[i] + 5);
            stringstream ss;
            for(int j = 0; j < 5; ++j)    
               ss << v[i][j];
            name[i] = ss.str();
            m[name[i]]++;
        }
        int mx = 0;
        TR(m, it)
           mx = max(mx, it->second);
        
        TR(m, it)
        {
           if(it->second == mx)
              for(int i = 0; i < students; ++i)
                 if(it->first == name[i])
                    b[i] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < students; ++i)
           cnt += b[i];
        printf("%d\n", cnt);
    }
    return 0;
}
