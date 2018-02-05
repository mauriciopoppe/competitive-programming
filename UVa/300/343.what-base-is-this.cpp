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
char a[50], b[50];
int min_base(char *a, int &size)
{
    int mx = 1;
    F(i,size)
       if(isupper(a[i]))
          mx = max(mx,a[i]-'A'+10);
       else 
          mx = max(mx,a[i]-'0');
    return mx + 1;   
}

LL to_base(char *a, int base, int &size)
{
   LL number = 0;
   F(i,size)
   {
      if(isupper(a[i]))
         number = number * base + a[i]-'A'+10;
      else
         number = number * base + a[i]-'0';
   }
   return number;
}


int main()
{
    while(scanf("%s%s",a,b) != EOF)
    {
         int size_a = strlen(a);
         int size_b = strlen(b);                   
         int min_a = min_base(a,size_a); 
         int min_b = min_base(b,size_b);
         while(min_a != 37 && min_b != 37)
         {
             LL a_converted = to_base(a, min_a, size_a);        
             LL b_converted = to_base(b, min_b, size_b);    
             if(a_converted == b_converted)
                break;
             if(a_converted > b_converted)
                ++min_b;
             else
                ++min_a;
         }
         if(min_a != 37 && min_b != 37)
            printf("%s (base %d) = %s (base %d)\n",a,min_a,b,min_b);
         else
            printf("%s is not equal to %s in any base 2..36\n",a,b);
    }
    return 0;
}
