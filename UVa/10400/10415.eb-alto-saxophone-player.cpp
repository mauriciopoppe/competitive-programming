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
    map<char, string> m;
  //         "1234567890"
    m['c'] = "0111001111";
    m['d'] = "0111001110";
    m['e'] = "0111001100";
    m['f'] = "0111001000";
    m['g'] = "0111000000";
    m['a'] = "0110000000";
    m['b'] = "0100000000";
    m['C'] = "0010000000";
    m['D'] = "1111001110";
    m['E'] = "1111001100";
    m['F'] = "1111001000";
    m['G'] = "1111000000";
    m['A'] = "1110000000";
    m['B'] = "1100000000";
    
    int v[10], pressed[10];
    char w[500];
    int cas;
    scanf("%d", &cas);
    gets(w);    
    while(cas--)
    {
        memset(v, 0, sizeof v);
        memset(pressed, 0, sizeof pressed);
        gets(w);
        for(int i = 0; w[i]; ++i)
        {            
            string note = m[w[i]];
            
            if(i == 0)
            {
                for(int j = 0; j < 10; ++j)
                   if(note[j] == '1')
                      v[j]++, pressed[j] = 1;
            }
            else
                for(int j = 0; j < 10; ++j)
                {
                   if(note[j] == '1')
                   {
                      if(pressed[j])
                         continue;
                      else
                         pressed[j] = 1,
                         v[j]++;
                   }
                   else
                      pressed[j] = 0;
                }
        }
        for(int i = 0; i < 10; ++i)
        {
           if(i)putchar(' ');
           printf("%d", v[i]);
        }
        NL;
    }
    return 0;
}
