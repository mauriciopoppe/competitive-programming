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
char m[101][101];
char w[55];
int main()
{
    //freopen("in2.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    scanf("%d",&cas);
    getchar();
    F(z,cas)
    {
       gets(w);
       int size = strlen(w);
       //printf("%d\n",size);
       memset(m, ' ', sizeof m);
       int x = 50, y = 0;
       int mn = 50, mx = 50;
       
       if(w[size - 1] == 'F')
          w[size] = 'C';
       else if(w[size - 1] == 'R')
          w[size] = 'F';
       else
          w[size] = 'C';
       
       for(int i = 0; i < size; ++i)
       {
           switch(w[i])
           {
                case 'R':
                     m[x][y++] = '/';
                     if(w[i + 1] != 'F')
                        --x;
                     break;
                case 'F':
                     m[x][y++] = '\\';
                     if(w[i + 1] == 'F')
                        ++x;
                     break;
                case 'C':
                     m[x][y++] = '_';
                     if(w[i + 1] == 'F')
                        ++x;
                     break;
           }
           mn = min(x, mn);
           mx = max(x, mx);
       }
       //m[x][y++] = w[size - 1];
       for(int i = mn; i <= mx; ++i)
       {
           int j;    
           for(j = size; j >= 0 ; --j)    
              if(m[i][j] != ' ')
              {
                 m[i][j + 1] = '\0';
                 break;
              }
           /*if(j < 0)
           {
               if(i == mn)
                  mn += 1;
               else
                  mx -= 1;
           }*/
       }
       printf("Case #%d:\n", z+1);
       for(int i = mn; i <= mx; ++i)
           printf("| %s\n",m[i]);
       printf("+-");
       for(int i = 0; i <= size; ++i)
          printf("-");
       NL;NL;
           
    }
    return 0;
}
