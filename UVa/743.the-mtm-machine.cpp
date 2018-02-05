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

string na = "NOT ACCEPTABLE";

string solve(string &s)
{
    if(s.find("0") != s.npos)
       return na;
    int k = 0;
    while(s.size() && s[0] == '3')   
       s = s.substr(1), ++k;
    if(s.size() == 1 || s[0] != '2')
       return na;
    s = s.substr(1);
    while(k--)
       s = s + "2" + s;
    return s;    
}

int main()
{
    string s;
    while(cin>>s && s != "0")
        printf("%s\n",solve(s).c_str());
    return 0;
}
