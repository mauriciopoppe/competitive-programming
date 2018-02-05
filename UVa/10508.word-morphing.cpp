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

int main()
{
    int n,L;
    while(scanf("%d%d",&n,&L)!=EOF)
    {
         char m[2000][L+3];
         bool b[n-1],u[L];
         scanf("%s",m[0]);
         scanf("%s",m[n]);
         n--;
         for(int i=1;i<n;i++)
              scanf("%s",m[i]);
         
         //first word
         memset(u,0,sizeof(u));
         fill(b,b+n,1);
         b[0]=0;
         printf("%s\n",m[0]);
         
         while(1)
         {
             int min=3000, ind=-1, last=0, ch=-1, i=0;
             for(i=0;i<n;i++)
             {
                  if(b[i])
                  {
                      int cc=0;    
                      for(int j=0;j<L;j++)
                         if(!u[j] && m[last][j]!=m[i][j])cc++,ch=j;
                      if(cc==1)
                      {
                             ind=i;
                             last=i;
                             b[i]=0;         
                             u[ch]=1;
                             break;
                      }
                  }           
             }   
             if(i==n)break;                  
             printf("%s\n",m[last]);
         }
         printf("%s\n",m[n+1]);                          
    }
    return 0;
}
