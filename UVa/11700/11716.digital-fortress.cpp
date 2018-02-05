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
    char buf[10002],w[10002];
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
          gets(buf);
          int len=strlen(buf);
          double sq=sqrt(len);
          if(ceil(sq)==floor(sq))
          {                                 
                int size=(int)(ceil(sq)),k=0;
                for(int i=0;i<size;i++)
                    for(int j=i;j<len;j+=size)
                       w[k++]=buf[j];
                w[k]='\0';
                printf("%s\n",w);                 
          }
          else printf("INVALID\n");    
    }
    return 0;
}
