#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

int main()
{
    int n,t,i;
    int v[101];
    while(scanf("%d",&n) && n)
    {
          memset(v,0,sizeof(v));
          for(i=0;i<n;++i)
          {
                    scanf("%d",&t);
                    ++v[t];
          }
          for(n=1;n<101;++n)
            if(v[n]){printf("%d",n);--v[n];break;}        
          for(;n<101;++n)
              if(v[n])
                 for(i=0;i<v[n];++i)
                    printf(" %d",n);
          printf("\n");
    }
    return 0;
}
