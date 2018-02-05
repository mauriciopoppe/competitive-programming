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
#define M 20002
#define S 10000
int bs[M];
int dpA[S+10],dpB[S+10];
int whereA[M],whereB[M];
int a[M],b[M];
int main()
{
    int na,nb;
    while(scanf("%d",&na) && na)
    {
        int sum = 0;                  
        memset(bs,0,sizeof bs);
        whereA[0] = whereB[0] = 0;
        dpA[0]=dpB[0]=0;
        F(i,na)
        {
            scanf("%d",&a[i]);
            whereA[a[i]+S] = i;
            bs[a[i]+S]++;
            dpA[i+1] = dpA[i] + a[i];
        }
        
        scanf("%d",&nb);
        F(i,nb)
        {
            scanf("%d",&b[i]);
            whereB[b[i]+S] = i;
            bs[b[i]+S]++;
            dpB[i+1] = dpB[i] + b[i];   
        }
        
        a[na] = b[nb] = M - 1;
        whereA[M - 1] = na;
        whereB[M - 1] = nb;
        bs[M - 1] = 2;
        dpA[na+1] = dpA[na] + a[na];
        dpB[nb+1] = dpB[nb] + b[nb];
        
        int j=0;
        FOR(i,0,M)
        {
            if(bs[i] > 1)
            {
                //printf("%d\n",i);
                //printf("%d\n",sum);
                if(j == 0)
                {     
                    sum += max(dpA[whereA[i] + 1], dpB[whereB[i] + 1]);
                    //printf("%d %d\n",dpA[whereA[i] + 1], dpB[whereB[i] + 1]);
                }
                else
                {
                    sum += max(dpA[whereA[i] + 1] - dpA[whereA[j] + 1], 
                           dpB[whereB[i] + 1] - dpB[whereB[j] + 1]);
                    //printf("%d %d\n",dpA[whereA[i] + 1] - dpA[whereA[j] + 1], 
                    //       dpB[whereB[i] + 1] - dpB[whereB[j] + 1]);
                }
                //SP;     
                j = i;
            }
        }
        printf("%d\n",sum-(M-1));
    }
    return 0;
}
