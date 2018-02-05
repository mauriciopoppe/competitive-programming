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
int v[14],k;
bitset<16> g;

void bt(int index)
{
     if(index==k)
         if(g.count()==6)
         {
             int i=0;
             for(;i<k;i++)
               if(g.test(i)){printf("%d",v[i]);break;}
             i++;
             for(;i<k;i++)
                if(g.test(i))printf(" %d",v[i]);
             printf("\n"); 
             //return;           
         }
         else return;
     else
     {
         g.set(index);
         bt(index+1);
         g.set(index,0);
         bt(index+1);
     }
}

int main()
{
    int j=0;
    while(scanf("%d",&k) && k)
    {
         if(j)printf("\n");
         j++;                
         for(int i=0;i<k;i++)
             scanf("%d",&v[i]);
         g.reset();
         bt(0);                       
    }
    return 0; 
}
