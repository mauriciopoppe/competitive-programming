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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 2147483647
char w[50000];
int main()
{
    int n;
    while(cin>>n && n)
    {
        int c=0;
        int j=0;
        while(n)
        {
             if(n%2)w[j++]='1',++c;
             else w[j++]='0';
             n/=2;
        }
        reverse(w,w+j);
        w[j]='\0';
        printf("The parity of %s is %d (mod 2).\n",w,c);
    }
    return 0;
}
