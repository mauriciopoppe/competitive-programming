#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define M 1048576
using namespace std;

int pw[21];

void gen()
{
     int x=0;
     for(int i=0;x<M;i++)
     {
         x=1<<i;    
         pw[i]=x;
     }     
}

int main()
{
    gen();
    int t,d,b,pp;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d%d",&d,&b);
    
         //get to the right level
         d--;
         
         int ac=pw[d];
         //printf("ac %d\n",ac);
         while(b>ac)
              ac+=pw[--d];
         
         int place=1;
         for(int i=0;i<d;i++)
              place+=pw[i];
         
         //printf("%d\n",place);
         while(1)
         {
              pp=pw[d--]/2;
              //printf("%d %d\n",pp,d);
              if(d<0)break;
              if(b%2==0)
              {
                  place+=pp;            
                  b=b/2;
              }
              else b=b/2+1;    
              //printf("place=%d b=%d\n",place,b);              
         }                                       
         printf("%d\n",place);
    }
    scanf("%d",&d);
    return 0;
}
