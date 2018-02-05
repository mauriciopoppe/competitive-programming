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
bool b[10000001];
int sum[20001];
int number;
int points;
int md(int n, int &modulus)
{
    if(n >= modulus)
       return n - modulus;
    return n;    
}

int main()
{
    int i,j,k,l;
    int total;
    int circular;
    int mx;
    int dif;
    int start;
    int min_solution;
    while(scanf("%d",&points) && points)
    {
        b[0] = 1;
        for(i = 0; i < points; ++i)       
        {
            scanf("%d",&number);
            if(i)
               sum[i] = sum[i - 1] + number;
            else
               sum[i] = number;
            b[sum[i]] = 1;
        }
        circular = points * 2; 
        for(i = points; i < circular; ++i)
        {
            sum[i] = sum[points - 1] + sum[i - points];
        }
        total = sum[points - 1];
        
        //sum[points - 1] = 0;
        min_solution = 2000000000;
        mx = 2000000000;
        //printf("min triangle %d\n",min_triangle);
        for(i = 0; i < points; ++i)
        {
            for(j = i + 1; j < i + points ; ++j)
            {
                //printf("J = %d\n",j);
                //printf("sum[i] = %d sum[j] = %d\n",sum[i],sum[j]);
                dif = sum[j] - sum[i];

                if(total % dif != 0)
                    continue;
                
                if(dif >= min_solution)
                   break;
                
                start = md(sum[i] + dif, total);
                int c = 0;
                int f = 0;
                
                while(1)
                {
                    ++c;
                    if(start == md(sum[i], total))
                       break;
                    start = md(start + dif, total);
                    if(!b[start])
                    {
                        f = 1;
                        //printf("No Solution\n");
                        //SP;
                        break;
                    }
                    //printf("start %d\n",start);
                    //SP;
                }
                //printf("f = %d\nc = %d\n",f,c);
                if(!f && c >= 3 && points - c < mx)
                {
                   mx = points - c;
                   min_solution = dif;
                   break;
                }
            }
        }
        if(mx != 2000000000)
           printf("%d\n",mx);
        else
           printf("-1\n");
        for(i = 0; i < points; ++i)
            b[sum[i]] = 0;
    }    
    return 0;
}
