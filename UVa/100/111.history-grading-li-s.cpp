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

int a[25],p[25],q[25],r[25],b[25],lis[25];
int main()
{
    int t,temp;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }       
    
    for(int i=1;i<=t;i++)
       q[p[i]]=i;    
       
    while(scanf("%d",&temp)!=EOF)
    {
        int c=1;                         
        b[temp]=c++;
        for(int i=2;i<=t;i++)
        {
             scanf("%d",&temp);
             b[temp]=c++;   
        }
        
        for(int i=1;i<=t;i++)
           r[q[b[i]]]=i;
        
        //printf("\n");
        //for(int i=1;i<=t;i++)
        //    printf("%d ",r[i]);
        //
        //printf("\n");
                              
        //lis
        fill(lis,lis+t+1,1);
        int max=1;
        for(int i=1;i<=t-1;++i)
          for(int j=i+1;j<=t;++j)
             if(r[j]>r[i] && lis[i]+1>lis[j])
                lis[j]=lis[i]+1,max>?=lis[j];
        
        printf("%d\n",max);                                  
    }
    return 0;
}
