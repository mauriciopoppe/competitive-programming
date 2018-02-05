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
#define M 32
int gcd(int a, int b){if(b==0)return a;return gcd(b,a%b);}
int main()
{
    char a[M],b[M];
    int t;
    scanf("%d",&t);
    F(q,t)
    {
          scanf("%s%s",a,b);
          int la=strlen(a),lb=strlen(b);
          int na=0,nb=0;
          F(i,la)
              na<<=1,na+=a[i]-'0';
          F(i,lb)
              nb<<=1,nb+=b[i]-'0';
          printf("Pair #%d: ",q+1);
          if(gcd(na,nb)>1)printf("All you need is love!\n");
          else printf("Love is not all you need!\n");
    }
    return 0;
}
