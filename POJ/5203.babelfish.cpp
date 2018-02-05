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
#define M 100000
int main()
{
    map<string,string> m;
    string a,b,gl;
    while(getline(cin,gl) && gl.size())    
    {
         stringstream ss(gl);
         ss>>a;ss>>b;
         m[b]=a;                 
    }
    while(cin>>a)
    {
         if(m.find(a)!=m.end())printf("%s\n",m[a].c_str());
         else printf("eh\n");
    }
    return 0;
}
