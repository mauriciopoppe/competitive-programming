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
    int cas;
    scanf("%d", &cas);
    string line, buf;
    getline(cin, line);    
    while(cas--)
    {
        int pieces = 0;
        getline(cin, line);
        stringstream ss(line);
        int f_back = 0, m_back = 0, f_front = 0, m_front = 0;
        while(ss >> buf)
        {
            if(buf[0] == 'F')
               ++f_back;
            else
               ++m_back;
            if(buf[1] == 'F')
               ++f_front;
            else
               ++m_front;
            ++pieces;
        }
        if(pieces > 1 && f_back == m_front && m_back == f_front)
           puts("LOOP");
        else
           puts("NO LOOP");
    }
    return 0;
}
