#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1000000
using namespace std;

int a[M][2],b[M][2];

int main()
{
    int w1,w2,x,y;
    while(scanf("%d",&w1) && w1)
    {
         int d=999999999;
         int s1=0,s2=0;
         for(;s1<w1;s1++)
            scanf("%d%d",&a[s1][0],&a[s1][1]);
         
         scanf("%d",&w2);
         for(;s2<w2;s2++)
            scanf("%d%d",&b[s2][0],&b[s2][1]);
         
         for(int i=0;i<s1;i++)
           for(int j=0;j<s2;j++)
              d<?=(abs(a[i][0]-b[j][0])+abs(a[i][1]-b[j][1]));
              
         printf("%d\n",d);            
    }    
    return 0;
}
