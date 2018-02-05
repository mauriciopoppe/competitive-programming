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
char w[5010];
LL one[5010],two[5010];
LL way[5010];
int main()
{
    while(gets(w) && w[0]!='0')
    {                          
        int size = strlen(w);
        if(size < 2)
        {
           puts("1");
           continue;
        }   
        F(i,size)
           one[i] = w[i] - '0';
        
        FOR(i,1,size)
           two[i] = one[i-1] * 10LL + one[i];

        way[0] = 1;
        if(one[1])
           way[1] = 1;
        else
           way[1] = 0;
           
        if(two[1] > 9 && two[1] < 27)
           way[1]++;
           
        for(int i=2;i<size;i++)
        {
           if(one[i])
             way[i] = way[i-1];
           else
             way[i] = 0;
           
           if(two[i] > 9 && two[i] < 27)
             way[i] += way[i-2];
        }
        printf("%lld\n",way[size-1]);
    }
    return 0;
}
