#include<iostream>
#include<algorithm>
#define M 2010
using namespace std;

int a[501][501],row,col,stmx[M][M],stmn[M][M];
int x,y,val,ind,i;

void update(int n, int b, int e)
{
     if(b==e)
          stmx[i][n]=stmn[i][n]=b;
     else
     {
          int m=((b+e)>>1);
          if(y<=m)update(2*n,b,m);
          else update(2*n+1,m+1,e);
          
          if(a[i][stmn[i][2*n]]<a[i][stmn[i][2*n+1]])
                    stmn[i][n]=stmn[i][2*n];                                                                            
              else stmn[i][n]=stmn[i][2*n+1];
              
          if(a[i][stmx[i][2*n]]>a[i][stmx[i][2*n+1]])
                stmx[i][n]=stmx[i][2*n];                                                                            
          else stmx[i][n]=stmx[i][2*n+1];
     }     
}

void build(int n, int b, int e)
{
     if(b==e)
     {
          for(int i=1;i<=row;i++)
             stmx[i][n]=stmn[i][n]=b;           
     }     
     else
     {
          int m=((b+e)>>1);
          build(2*n,b,m);
          build(2*n+1,m+1,e);
          
          for(int i=1;i<=row;i++)
          {
              if(a[i][stmn[i][2*n]]<a[i][stmn[i][2*n+1]])
                    stmn[i][n]=stmn[i][2*n];                                                                            
              else stmn[i][n]=stmn[i][2*n+1];
              
              if(a[i][stmx[i][2*n]]>a[i][stmx[i][2*n+1]])
                    stmx[i][n]=stmx[i][2*n];                                                                            
              else stmx[i][n]=stmx[i][2*n+1];  
          }                  
     }
}

int querymx(int n, int b, int e)
{
     if(b>=x && e<=y)return stmx[ind][n];
     int m=((b+e)>>1);
     if(y<=m)return querymx(2*n,b,m);
     else if(x>m)return querymx(2*n+1,m+1,e);
     else
     {
          int p1=querymx(2*n,b,m),p2=querymx(2*n+1,m+1,e);
          if(a[ind][p1]>a[ind][p2])return p1;
          return p2;           
     }
}

int querymn(int n, int b, int e)
{
     if(b>=x && e<=y)return stmn[ind][n];
     int m=((b+e)>>1);
     if(y<=m)return querymn(2*n,b,m);
     else if(x>m)return querymn(2*n+1,m+1,e);
     else
     {
          int p1=querymn(2*n,b,m),p2=querymn(2*n+1,m+1,e);
          if(a[ind][p1]<a[ind][p2])return p1;
          return p2;                    
     }
}

int main()
{
    scanf("%d%d",&row,&col);
    int j;
    for(i=1;i<=row;++i)
       for(j=1;j<=col;++j)
         scanf("%d",&a[i][j]);
    
    build(1,1,row);
 
    int q;
    char c;
    scanf("%d",&q);
    while(q--)
    {
         cin>>c;
         if(c=='q')
         {
              int x1,x2,y1,y2;
              scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
              
              x=y1;
              y=y2;
              
              int mx=a[x1][y1],mn=a[x1][y1];
              for(i=x1;i<=x2;i++)
              {
                  ind=i;    
                  int q1=querymx(1,1,col);
                  int q2=querymn(1,1,col);
                  if(a[i][q1]>mx)mx=a[i][q1];
                  if(a[i][q2]<mn)mn=a[i][q2];            
              }
              printf("%d %d\n",mx,mn);              
         }     
         else
         {
              scanf("%d %d %d",&i,&y,&val);
              a[i][y]=val; 
              //for(int w=1;w<=10;w++)printf("%d ",stmx[i][w]);printf("\n");
              update(1,1,row); 
              //for(int w=1;w<=10;w++)printf("%d ",stmx[i][w]);printf("\n");
         }     
    }
    return 0;
}
