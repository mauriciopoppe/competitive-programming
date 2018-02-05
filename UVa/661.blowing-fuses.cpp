#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    int n,m,c,now,aux,j=1,max;
    bool f;
    int v[21],s[21];
    while(scanf("%d%d%d",&n,&m,&c) && n+m+c!=0)
    {
         now=0,max=0,f=true;                          
         memset(s,0,sizeof(s));
         for(int i=0;i<n;i++)
             scanf("%d",&v[i+1]);                          
         
         int i;
         for(i=0;i<m;i++)
         {
             scanf("%d",&aux);    
             if(!s[aux]){now+=v[aux];s[aux]=1;if(now>max)max=now;}
             else {now-=v[aux];s[aux]=0;}
             if(now>c)f=false;    
         }   
         
         printf("Sequence %d\n",j++);
         if(f)printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",max);
         else printf("Fuse was blown.\n");
         printf("\n");
    }
    return 0;
}
