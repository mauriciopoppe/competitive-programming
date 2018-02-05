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
    map<char,int> m;
    m['a']=m['d']=m['g']=m['j']=m['m']=m['p']=m['t']=m['w']=m[' ']=1;
    m['b']=m['e']=m['h']=m['k']=m['n']=m['q']=m['u']=m['x']=2;
    m['c']=m['f']=m['i']=m['l']=m['o']=m['r']=m['v']=m['y']=3;
    m['s']=m['z']=4;
    int n;
    char w[1000000];
    scanf("%d",&n);
    getchar();
    F(q,n)
    {
         gets(w);
         int c=0,s=strlen(w);
         F(i,s)
              c+=m[w[i]];             
         printf("Case #%d: %d\n",q+1,c);  
    }
    return 0;
}
