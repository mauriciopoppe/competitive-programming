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
string w1, w2;
int total, word_size;
int i, j;
char st[500000];
char op[500000];

void bt(int k, int st_size)
{
     if(k == total)
     {
         for(int z = 0; z < total; ++z)
         {
            if(z)putchar(' ');      
            putchar(op[z]);
         }
         NL;
     }
     else
     {
         /*for(int z = 0; z < total; ++z)
         {
            if(z)putchar(' ');      
            putchar(op[z]);
         }
         NL;
         SP;*/
         if(i < word_size)
         {
            op[k] = 'i';
            char t = st[st_size];
            st[st_size] = w1[i];
            ++i;
            bt(k + 1, st_size + 1);
            --i;
            st[st_size] = t;
         }
         /*printf("%d %d\n", st_size, j);
         if(st_size)
            printf("%c\n", st[st_size - 1]);*/
         if(!st_size || st[st_size - 1] != w2[j])
            return;
         op[k] = 'o';
         ++j;
         bt(k + 1, st_size - 1);
         --j;
         /*puts("END LOOP");         
         SP;   */      
     }     
}

void solve()
{
    if(w1.size() != w2.size())
       return;
    string cw1 = w1, cw2 = w2;
    sort(ALL(cw1));
    sort(ALL(cw2));
    if(cw1 != cw2)
       return;
    word_size = w1.size();
    total = word_size * 2;
    i = j = 0;
    memset(op, 'X', sizeof op);
    bt(0, 0);       
}

int main()
{
    while(cin >> w1 >> w2)
    {
         printf("[\n");
         solve();
         printf("]\n");
    }
    return 0;
}
