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
char code[2][35];
char w[85];
int where;
int to_dec(string s)
{
    bitset<10> b(s);
    return b.to_ulong();
}

void work()
{
    int size = strlen(w); 
    where = 0;
    for(int i = 0; i < size; i += 5)
    {
       string s = string(w + i, w + i + 5);
       //cout << s << endl;
       int dec = to_dec(s);
       //printf("%d\n",dec);
       if(dec == 27)
          where = 0;
       else if(dec == 31)
          where = 1;
       else
          putchar(code[where][dec]);
    }
    printf("\n");
}

int main()
{
    gets(code[0]);
    gets(code[1]);
    while(gets(w))
       work();
    return 0;
}
