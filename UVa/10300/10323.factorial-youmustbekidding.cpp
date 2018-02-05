#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
LL a[]={40320,362880,3628800,39916800,479001600,6227020800LL};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
         if(n<0)
         {
              n=-n;  
              if(n&1)  printf("Overflow!\n");
              else printf("Underflow!\n");
         }                     
         else if(n<8)printf("Underflow!\n");
         else if(n>13)printf("Overflow!\n");
         else printf("%lld\n",a[n-8]);                     
    }    
    return 0;
}
