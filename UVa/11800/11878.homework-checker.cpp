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
char w[50];

void kill_spaces()
{
     char str[50];
     int j = 0;
     for(int i =0; w[i];++i)
        if(w[i] != ' ')
           str[j++] = w[i];     
     str[j] = '\0';
     memcpy(w, str, sizeof str);
}

int main()
{
    int c = 0,x,y,z;
    char op;
    while(gets(w))
    {
       kill_spaces();           
       if(sscanf(w,"%d%c%d=%d",&x,&op,&y,&z) == 4)
          if(op == '+')
          {
             if(x + y == z)
                ++c;
          }
          else if(op == '-')           
          {
              if(x - y == z)
                 ++c; 
          }
    }
    printf("%d\n",c);
    return 0;
}
