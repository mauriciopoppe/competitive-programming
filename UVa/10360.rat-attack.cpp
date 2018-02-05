#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define C 1100
using namespace std;
static int m[C][C];
/*
int **m=new int*[C];
    for(int i=0;i<C;i++)
       m[i]=new int[C];
 */      
int main()
{
    int n;
    cin>>n;
    
    while(n--)
    {
         for(int i=0;i<C;i++)
           for(int j=0;j<C;j++)
              m[i][j]=0;
         int r,rats,a,b,c;
         cin>>r>>rats;
         for(int q=0;q<rats;q++)          
         {
             cin>>a>>b>>c;    
             int j=a-r,k=b-r;
             if(j<0)j=0;
             if(k<0)k=0;
             
             for(int i=j;i<a+r+1;i++)
               for(int l=k;l<b+r+1;l++)
                  m[i][l]+=c;
         }     
         
         
         int sum=0,x=0,fi=-1,fj=-1;
         
         for(int i=0;i<C;i++)
            for(int j=0;j<C;j++)
               if(m[i][j]>x){x=m[i][j];fi=i;fj=j;}
         //printf("%d %d",m[4][4],m[6][6]);
         printf("%d %d %d\n",fi,fj,x);
    }
    return 0;
}
