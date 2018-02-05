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
int pw10[] = {1,10,100,1000,10000,100000,1000000,10000000};
int numbers[] = {-1,9,189,2889,38889,488889,5888889,68888889,100000001};
int main()
{    
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int i;
        for(i = 1; n > numbers[i]; ++i); //find the number of digits        
        n -= numbers[i - 1];

        //see which digit is
        int pos = n % i;
        n = n / i;
        
        //printf("%d %d %d\n", i, pos, n);
        int value;    
        if(pos == 0)
            value = (n - 1) % 10;
        else
        {
            if(pos == 1) value = (n / pw10[i - 1]) % 10 + 1;
            else value = (n / pw10[i - pos]) % 10;
        }
        printf("%d\n", value);
    }
    return 0;
}
