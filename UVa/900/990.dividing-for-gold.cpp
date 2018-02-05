#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1050
using namespace std;
int a[M][M],w[31],v[31],w2[31];
int main()
{
    int t,x,o,cc=0;
    while(scanf("%d%d",&t,&x)!=EOF)
    {
          if(cc)printf("\n");
          ++cc;                         
          scanf("%d",&o);                         
          for(int i=1;i<=o;i++)
          {
              scanf("%d%d",&w2[i],&v[i]);
              w[i]=3*x*w2[i];
          }
          
          for(int i=0;i<=t;i++)a[i][0]=a[0][i]=0;
                    
          for(int i=1;i<=o;i++)
          {
              for(int j=1;j<=t;j++)
              {
                   if(j>=w[i])
                      a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+v[i]);
                   else a[i][j]=a[i-1][j];   
              }            
          }        
          
          printf("%d\n",a[o][t]);
          vector<int> sol;
          //bt
          int i=o,k=t;
          
          for(int i=o;i>0;i--)
          {
              if(a[i][k]!=a[i-1][k])
                 sol.push_back(i),k-=w[i];    
          }
          
          int len=sol.size();
          printf("%d\n",len);
          for(int i=len-1;i>=0;i--)
             printf("%d %d\n",w2[sol[i]],v[sol[i]]);
                                                               
    }
    return 0;
}
