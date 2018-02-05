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
typedef pair<int, int> pii;
typedef vector<int> vi;
char w[5000];
int main()
{
    int n;
    cin >> n;
    while(n--){
        scanf("%s", w);
        int size = strlen(w);
        int total = 1 + size;
        for(int i = 1; i < size; ++i){
            if(w[i] >= w[i - 1])    
                total += w[i] - w[i - 1];
            else
                // z a
                total += 'z' - w[i - 1] + w[i] - 'a' + 1;
        }
        //printf("%d", total);
        if(total <= size * 11)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
