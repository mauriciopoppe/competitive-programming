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
#define M 75
char ct[M],pt[M];

int main()
{
    int key;
    while(scanf("%d",&key) && key)
    {
        scanf("%s",ct);
        int size = strlen(ct);
        int i;
        for(i = 0; ct[i]; ++i)
        {
            int cc = ct[i] - 'a' + 1;
            if(ct[i] == '_')cc = 0;
            if(ct[i] == '.')cc = 27;
            int pc = (cc + i) % 28;
            //printf("%d %d %d\n",cc,pc,(key * i) % size);
            if(pc == 0)pt[(key * i) % size] = '_';
            else if(pc == 27)pt[(key * i) % size] = '.';
            else pt[(key * i) % size] = pc + 'a' - 1;
        }
        pt[size] = '\0';
        printf("%s\n",pt);
    }
    return 0;
}
