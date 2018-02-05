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

int v[1500];
int main()
{
    int q,n,t,m,cros,last,timelast,trips;
    scanf("%d",&q);
    ++q;
    while(--q)
    {
         scanf("%d%d%d",&n,&t,&m);
         for(int i=0;i<m;i++)
              scanf("%d",&v[i]);
         
         //first take m%n cars
         int time=0;
         if(m%n!=0)
            time=v[(m%n)-1];
         else time=v[n-1];
         
         int aux=m/n;
         if(m%n!=0)aux++;
         trips=aux;
         aux=aux*2-1;
         time+=(aux)*t;
         
         if(v[m-1]+t>time)time=v[m-1]+t;
         printf("%d %d\n",time,trips);                  
    }
    return 0;
}
