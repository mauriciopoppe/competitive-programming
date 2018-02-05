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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{    
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string w;
    while(getline(cin,w))
    {              
         if(isdigit(w[0]))
         {
              reverse(ALL(w));
              string::iterator it=w.begin();
              for(;it!=w.end();)
              {
                  string temp;   
                  if(*it=='1')temp=string(it,it+3),it+=3;
                  else temp=string(it,it+2),it+=2;
                  putchar(atoi(temp.c_str()));                      
              }
              NL;
         }
         else
         {
              stringstream ss;
              TR(w,it)
              {
                  ss<<(int)*it;
              }
              string temp=ss.str();
              reverse(ALL(temp));
              printf("%s\n",temp.c_str());
         }
    }
    return 0;
}
