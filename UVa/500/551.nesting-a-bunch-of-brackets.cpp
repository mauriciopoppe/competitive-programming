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
map<char, int> m;
char w[5000], line[5000];

int parse(char *w, char *line, char *match, char assign)
{
    //printf("[%s] [%s]\n", w, line);
    int size = 0;
    int len = strlen(w);
    for(int i = 0; i < len; ++i)
       if(!strncmp(w + i, match, 2))
       {
          line[size++] = assign;
          ++i;
       }
       else
         line[size++] = w[i];
    line[size] = '\0';
    //printf("%d %s\n", size, line);
    return size;
}

struct sym{
       char c;
       int pos;
} a_sym;

int solve(int size)
{
    deque<sym> q;
    int t;
    for(int i = 0; i < size; ++i)
       if(t = m[w[i]])
       {
            if(t & 1)
               a_sym.c = w[i],
               a_sym.pos = i,
               q.push_front(a_sym);
            else
            {
               if(!q.size())return i;
               a_sym = q.front();
               if(t - 1 != m[a_sym.c])
                  return i;
               q.pop_front();
            }
       }
    if(q.size())
       return size;
    return -1;
}


int main()
{
    m[2] = 1;
    m[3] = 2;    
    m['('] = 11;
    m[')'] = 12;
    m['['] = 21;
    m[']'] = 22;
    m['{'] = 31;
    m['}'] = 32;
    m['<'] = 41;
    m['>'] = 42;
    

    int t;
    while(gets(w))
    {
        parse(w, line, "(*", 2);        
        int size = parse(line, w, "*)", 3);
        int k = solve(size);
        if(k == -1)
           puts("YES");
        else
           printf("NO %d\n", k + 1);
    }
    return 0;
}
