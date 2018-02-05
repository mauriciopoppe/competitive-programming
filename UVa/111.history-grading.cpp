#include<iostream>
#define max(a,b) (a>=b?a:b)
using namespace std;
int main()
{
    int n,t;
    int a[21],b[21],m[21][21];
    cin>>n;
    for(int i=0;i<n;i++)    
       {
            cin>>t;
            a[t-1]=i+1;
       }

    /*for(int i=0;i<n;i++)    
            printf("%d ",a[i]);*/
    while(cin>>t)
    {
          m[0][0]=0;
          b[t-1]=1;
          for(int i=1;i<n;i++)    
                  {
                  cin>>t;
                  b[t-1]=i+1;
                  m[0][i]=m[i][0]=0;
                  }
             
          for(int i=0;i<n;i++)
              for(int j=0;j<n;j++)
                  if(a[i]==b[j])m[i+1][j+1]=m[i][j]+1;
                  else
                     m[i+1][j+1]=max(m[i][j+1],m[i+1][j]);
          printf("%d\n",m[n][n]);
    }    
}
