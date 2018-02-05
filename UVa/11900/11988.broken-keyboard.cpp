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
enum{HEAD,TAIL};
int main()
{
    char c;
    char w[100002],end[100002];
    deque<char>::reverse_iterator it;
    while(gets(w))
    {
         deque<char> q[2];         
         bool f=0,hasTail=0;
         for(int i = 0; w[i]; ++i)
         {
              if(w[i]==']')
              {
                  if(hasTail)
                  {
                      for(it = q[TAIL].rbegin(); it != q[TAIL].rend(); ++it)
                         q[HEAD].push_front(*it);
                      q[TAIL].clear();                              
                      hasTail=0;
                  }         
                  f=0;
              }
              else if(w[i]=='[')
              {
                  if(hasTail)
                  {
                      for(it = q[TAIL].rbegin(); it != q[TAIL].rend(); ++it)
                         q[HEAD].push_front(*it);
                      q[TAIL].clear();
                      hasTail=0;
                  }         
                  f=1;
              }
              else
              {
                  if(!f)
                        q[HEAD].push_back(w[i]);
                  else
                        q[TAIL].push_back(w[i]),hasTail=1;
              }
         }
         int i=0;
         TR(q[TAIL], it)
            end[i++] = *it;
         TR(q[HEAD], it)
            end[i++] = *it;
         end[i]='\0';
         printf("%s\n",end);
    }   
    return 0;
}
