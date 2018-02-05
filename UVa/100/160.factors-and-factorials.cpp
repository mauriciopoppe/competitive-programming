#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int f[101][101],a[101];

int main()
{
    a[2]=f[2][2]=1;
    for(int i=3;i<101;i++)
    {
         memcpy(f[i],f[i-1],sizeof(f[i-1]));
         int t=i;
         while(!(t&1))
         {
             ++f[i][2];               
             t>>=1;
         }         
         if(t==1)continue;
         for(int j=3;j*j<=t;j+=2)
              while(t%j==0)
              {
                   ++f[i][j];
                   t/=j;         
              }         
         if(t>1)++f[i][t];  
    }
    
    int n;
    while(scanf("%d",&n) && n)
    {
         printf("%3d! =",n);
         printf("%3d",f[n][2]);
         int c=1;
         for(int i=3;i<101;i+=2)                                               
         {
             if(f[n][i])
             {
                 if(c==15)printf("\n      ");
                 ++c;
                 printf("%3d",f[n][i]);                  
             }            
         }
         printf("\n");
    }
    return 0;
}
