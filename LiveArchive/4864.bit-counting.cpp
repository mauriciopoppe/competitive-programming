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
int dp[70];
LL pow2[20];
char bin[70]; 
LL a, b;
int x;

int count_bits(int number)
{
    int bits_set_to_one = 0;
    while(number)
    {
         bits_set_to_one++;
         number &= number - 1;
    }    
    return bits_set_to_one;
}

int first_dp(int n)
{
    if(dp[n] != -1) return dp[n];
    return dp[n] = first_dp(count_bits(n)) + 1;
}

int total_1;
LL total = 0;
LL solve(int num_ones, int k)
{
    if(k < 0)
    {
        if(num_ones == total_1)
           return 1;
        return 0; 
    }
    if(bin[k] == 1)
       return solve(num_ones, k - 1) + ();
}

int to_bin(char *bin, LL n)
{
     int size = 0;
     while(n)
        bin[size++] = n % 2LL,
        n /= 2;        
     return size;
}

int main()
{
    memset(dp, -1, sizeof dp);
    dp[1] = 0;
    for(int i = 2; i <= 61; ++i)
       first_dp(i);
    pow2[0] = 1;
    for(int i = 1; i <= 61; ++i)
       printf("%d) %d\n", i, dp[i]);
       
    while(scanf("%lld%lld%lld", &a, &b, &x) && (a + b + x) != 0)
    {
         a--;
         if(x >= 5)
         {
              printf("0\n");
              continue;
         }
         
         //find the location of the last bit for a
         int last_bit = -1;
         for(int i = 0; i <= 18; ++i)
            if(a & pow2[i])
               last_bit = i;
         
         //convert number to binary
         int size = to_bin(bin, a);
               
         printf("%d\n", last_bit);
         LL total1 = 0;
         for(int i = 1; i <= last_bit + 1; ++i)
              if(dp[i] + 1 == (int)x)
              {
                  total_1 = i;
                  big_number = a;
                  solve(0, size - 1);
                  total1 += total;
              }
         
         //find the location of the last bit for b
         last_bit = -1;
         for(int i = 0; i <= 18; ++i)
            if(b & pow2[i])
               last_bit = i;
          
         LL total2 = 0;
         for(int i = 1; i <= last_bit + 1; ++i)
              if(dp[i] + 1 == (int)x)
              {
                  number = 0;
                  total = 0;
                  total_1 = i;
                  big_number = b;
                  total_digits = last_bit + 1;
                  solve(0, 0);
                  total2 += total;
              }

         printf("%lld %lld\n", total1, total2);
         printf("%lld\n", total2 - total1);
    }           
    return 0;
}
