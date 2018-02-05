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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    int n, D, k;
    string w, subject;
    scanf("%d", &cas);
    F(z, cas)
    {
        scanf("%d", &n);
        map<string, int> m; 
        for(int i = 0; i < n; ++i)
        {
           cin >> w >> k;
           m[w] = k;
        }
        scanf("%d", &D);
        cin >> subject;
        printf("Case %d: ", z + 1);
        if(!m[subject])
           puts("Do your own homework!");
        else if(m[subject] <= D)
           puts("Yesss");
        else if(m[subject] <= D + 5)
           puts("Late");
        else
           puts("Do your own homework!");
    }
    
    return 0;
}
