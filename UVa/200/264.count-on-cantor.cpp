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
    
    int n,c=0;
    while(scanf("%d",&n)!=EOF)
    {
         double x=((-1+sqrt(1+8*n))/2.0);                          
         //printf("%lf\n",x);
         
         int s=(int)(ceil(x));
         int bf=(s-1)*s/2;
         //printf("%d %d\n",s,bf);
         if(s%2==0)
         {     
              int i=1;
              int j=s;
              bf++;
              while(bf!=n)
              { 
                  i++;
                  j--;    
                  bf++;        
              }
              printf("TERM %d IS %d/%d\n",n,i,j);                           
         }
         else
         {
              int i=s;
              int j=1;
              bf++;
              while(bf!=n)
              { 
                  i--;
                  j++; 
                  bf++;           
              }
              printf("TERM %d IS %d/%d\n",n,i,j);                                      
         }
    }
    return 0;
}
