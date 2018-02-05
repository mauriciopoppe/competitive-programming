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
int n=8,ind=0;
int m[100][8];

int cand(int a[], int c[], int k)
{
    int i=0,j=0,candidates=0;
    for(;i<n;i++)
    {
          for(j=0;j<k;j++)
             if(abs(j-k)==abs(i-a[j]) || i==a[j])break;
          if(j==k)c[candidates++]=i;       
    }    
    return candidates;
}

void bt(int a[], int k)
{
     if(k==n)
     {
          for(int i=0;i<8;i++)
              m[ind][i]=a[i];
          ind++;   
     }     
     else
     {
          int c[9];
          int nc=cand(a,c,k);
          for(int i=0;i<nc;i++)
          {
              a[k]=c[i];
              bt(a,k+1);    
          }
     }
}

void print(int i)
{
     for(int j=0;j<n;j++)     
        printf(" %d",m[i][j]+1);
     printf("\n");
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int a[9];
    bt(a,0);
    int t,x,y;
    scanf("%d",&t);
    for(int q=0;q<t;q++)
    {
         if(q)printf("\n");
         scanf("%d%d",&x,&y);
         int sc=0;
         for(int i=0;i<ind;i++)
         {   
              if(!i)
              {
                   printf("SOLN       COLUMN\n");
                   printf(" #      1 2 3 4 5 6 7 8\n\n");
              }
                   
              if(m[i][y-1]==x-1)
              {                     
                   printf("%2d     ",++sc);             
                   print(i);   
              }
         }                    
    }
    return 0;
}
