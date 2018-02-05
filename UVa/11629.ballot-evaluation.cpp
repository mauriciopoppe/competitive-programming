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
#define E 1e-9
bool check(int &p, string &buf, int &f)
{
    if(buf == "=")
       return p == f;
    if(buf == ">")
       return p > f;
    if(buf == "<")
       return p < f;
    if(buf == ">=")
       return p >= f;
    if(buf == "<=")
       return p <= f;
    return 0;
}

int main()
{
    int parties, guess;
    int a, b, p;
    string w;
    while(scanf("%d%d", &parties, &guess) != EOF)
    {
        map<string, int> m;
        for(int i = 0; i < parties; ++i)
        {
           cin >> w;
           scanf("%d.%d", &a, &b);       
           m[w] = a * 10 + b;
        }
        getline(cin, w);
        for(int i = 0; i < guess; ++i)
        {
            getline(cin, w);
            stringstream ss(w);
            string buf, final;
            int f;
            p = 0;
            ss >> buf;
            p += m[buf];
            while(ss >> buf && buf == "+")
            {
               ss >> buf;
               p += m[buf];
            }
            
            ss >> final;
            sscanf(final.c_str(), "%d", &a);
            f = a * 10;
            //printf("%d %d\n", p, f);
            if(check(p, buf, f))
               printf("Guess #%d was correct.\n", i + 1);
            else
               printf("Guess #%d was incorrect.\n", i + 1);
        }
    }
    return 0;
}
