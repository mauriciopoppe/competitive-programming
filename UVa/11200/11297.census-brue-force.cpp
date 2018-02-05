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
static int a[501][501];

int main()
{
    int t,x1,y1,x2,y2,col,row,q,i,j;
    char w;
    scanf("%d %d",&col,&row);
    for(i=0,j;i<row;++i)
      for(j=0;j<col;++j)
         scanf("%d",&a[i][j]);
    
    scanf("%d",&q);
    ++q;
    while(--q)
    {
         cin>>w;
         if(w=='q')
         {
               scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
               --x1;
               --y1;
               int mn=a[x1][y1],mx=a[x1][y1];
               for(i=x1;i<x2;++i)
                  for(j=y1;j<y2;++j)
                  {
                       if(a[i][j]>mx)mx=a[i][j];             
                       if(a[i][j]<mn)mn=a[i][j];
                  }             
               
               printf("%d %d\n",mx,mn);
         }               
         else
         {
               scanf("%d %d %d",&x1,&y1,&t);
               a[x1-1][y1-1]=t;              
         }
    }
    return 0;
}
