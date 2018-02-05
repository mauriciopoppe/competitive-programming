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

struct node{
       int mx,l,r,lsum,rsum,col;
       } st[262200][17];
       
int a[100002];

void print(int n)
{
     for(int i=0;i<n;i++)
     {
             printf("%d ",a[i]);
             for(int j=0;j<n;j++)printf("%d ",st[i][j].mx);
             printf("\n");
     }
     printf("\n");     
}

void process(int n)
{
      int i, j;
   
      //initialize M for the intervals with length 1
      for (i = 0; i < n; i++)
      {
          st[i][0].mx = 1;
          st[i][0].l = st[i][0].r = st[i][0].col = a[i];
          st[i][0].lsum = st[i][0].rsum = 1;
      }
     
      //compute values from smaller to bigger intervals
      for (j = 1; 1 << j <= n; j++)
      {
          int s=1<<j;
          int s2=1<<(j-1);
          for (i = 0; i + s - 1 < n; i++)
          {
              st[i][j].mx=max(st[i][j - 1].mx,st[i+s2][j - 1].mx);
              st[i][j].l=st[i][j-1].l;
              st[i][j].r=st[i+s2][j-1].r;
              st[i][j].lsum=st[i][j-1].lsum;
              st[i][j].rsum=st[i+s2][j-1].rsum;
              
              if(st[i][j-1].col==st[i+s2][j-1].l)st[i][j].lsum+=st[i+s2][j-1].lsum;
              if(st[i+s2][j-1].col==st[i][j-1].r)st[i][j].rsum+=st[i][j-1].rsum;
              if(st[i][j-1].col==st[i+s2][j-1].col)st[i][j].col=st[i][j-1].col;
              else st[i][j].col=-1;
             
              if(st[i][j-1].r==st[i+s2][j-1].l)
                 if(st[i][j-1].rsum+st[i+s2][j-1].lsum>st[i][j].mx)
                    st[i][j].mx=st[i][j-1].rsum+st[i+s2][j-1].lsum;    
              print(10);
              system("pause");
          }
    }
  }  

int main()
{
    //freopen("FrequentValuesRMQ.txt","r",stdin);
    //freopen("FVout.txt","w",stdout);

    int n;
    int i,j,k,q;
    while(scanf("%d",&n) && n)
    {
          scanf("%d",&q);
          for(int x=0;x<n;x++)scanf("%d",&a[x]);
          process(n);
          while(q--)
          {
               scanf("%d%d",&i,&j);
               i--;
               j--;
               if(i-j==0)k=0;
               else k=(int)(round(log2(j-i)));
               //printf("%d\n",k);
               printf("%d\n",max(st[i][k].mx,st[j-(1<<k)+1][k].mx));                
          }
    }
    return 0;
}
