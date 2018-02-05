#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define M 102
using namespace std;
int a[M][M];
int mx=0;
int m,n;

void print(int b[M][M])
{
     for(int i=0;i<m;i++)
        {for(int j=0;j<n;j++)
           printf("%d ",b[i][j]);printf("\n");}     
}

void bt(int c, int i, int j, int b[M][M])
{
       b[i][j]=1;    
       int last=a[i][j];
       //printf("c = %d  || %d %d %d\n\n",c,i,j,last);     
       if(i-1>=0 && a[i-1][j]<last && !b[i-1][j])
            {bt(c+1,i-1,j,b);b[i-1][j]=0;}  
       else if(c>mx)mx=c;
       
       if(j-1>=0 && a[i][j-1]<last && !b[i][j-1])
            {bt(c+1,i,j-1,b);b[i][j-1]=0;} 
       else if(c>mx)mx=c;
       
       if(i+1<m && a[i+1][j]<last && !b[i+1][j])
            {bt(c+1,i+1,j,b);b[i+1][j]=0;}  
       else if(c>mx)mx=c;   
       
       if(j+1<n && a[i][j+1]<last && !b[i][j+1])
            {bt(c+1,i,j+1,b);b[i][j+1]=0;}  
       else if(c>mx)mx=c;    
}

int main()
{
    int t;
    string name;
    scanf("%d",&t);
    while(t--)
    {
          int b[M][M];   
          
          cin>>name;   
          scanf("%d%d",&m,&n);
          for(int i=0;i<m;i++)
             for(int j=0;j<n;j++)         
                scanf("%d",&a[i][j]);
          
          mx=0; 
          for(int i=0;i<m;i++)
             for(int j=0;j<n;j++)         
             {
                   
                 memset(b,0,sizeof(b));    
                 //print(b);
                 bt(1,i,j,b);
                 //printf("%d %d %d %d\n",a[i][j],i,j,mx);
                 //printf("\n\n");
                 //system("pause");
             }
          printf("%s: %d\n",name.c_str(),mx);
    }
    return 0;
}
