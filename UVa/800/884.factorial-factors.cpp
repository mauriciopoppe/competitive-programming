#include<stdio.h>
#include<cmath>
using namespace std;

int f[1000001],a[1000001];

int main()
{
    f[1]=a[1]=0;
    f[2]=a[2]=1;
    int c,t;
    for(int i=3;i<1000001;i++)
    {
        if(!(i&1))
        {
            a[i]=a[2]+a[i>>1];  
            f[i]=f[i-1]+a[i];
            continue;      
        }
        
        t=(int)sqrt(i);
        c=0;
        for(int k=3;k<=t;k+=2)
             if(i%k==0)
             {
                   c=k;
                   break;
             }
        
        if(c)a[i]=a[c]+a[i/c];
        else a[i]=1;
        f[i]=f[i-1]+a[i];
    }
    
    int n;
    while(scanf("%d",&n)!=EOF)
      printf("%d\n",f[n]);
    
    return 0;
}
