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
char w[500];
char temp[500];

int check_e(char c, char *str)
{
    int a,b;
    char x;
    if(c == 'e' || c == 'E')
    {
        if(sscanf(str,"%d%c%d",&a,&c,&b) == 1)
           return 1;
        return 0;
    }
    return 0;    
}

int solve()
{
    int a,b,x;
    char c;
    char str[500];
    //printf("here");
    //sscanf(w,"%*d%c%s",&c,str);
    //printf("%c %s\n",c,str);
    if(sscanf(w,"%*d%c%s",&c,str) != 2)
       return 0;
    
    if(c == '.')
    {
         if((x = sscanf(str,"%d%c%s",&a,&c,temp)) == 3)
             return check_e(c,temp);
         if(x == 1)
            return 1;
         return 0;    
    }
    else return check_e(c,str);
    return 0;
}

int main()
{
    while(scanf("%s",w) && w[0] != '*')
    {
       if(solve())
          printf("%s is legal.\n",w);
       else 
          printf("%s is illegal.\n",w);
    }
    return 0;
}
