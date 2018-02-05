#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main()
{
    int n,x,a;
    while(scanf("%d",&n) && n)
    {
         map<int,int> m;
         long long t=0;
         for(int j=0;j<n;j++)
         {        
             scanf("%d",&x);
             for(int i=0;i<x;i++)
             {
                 scanf("%d",&a);
                 m[a]++;
             }
             
             t+=m.rbegin()->first-m.begin()->first;
             m.rbegin()->second--;
             m.begin()->second--;
             if(m.rbegin()->second==0)
                m.erase(m.rbegin()->first);
             if(m.begin()->second==0)
                m.erase(m.begin()->first);
             
             //printf("total=%d\n",t);            
         }             
         printf("%lld\n",t);
    }
    return 0;
}
