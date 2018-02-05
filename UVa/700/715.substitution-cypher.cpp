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

char m[256];
char buf[70];
char a[50],b[50];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
          memset(m,0,sizeof(m));    
          gets(a);
          gets(b);
          int s=strlen(b);
          for(int i=0;i<s;i++)
               m[a[i]]=b[i];                           
          
          printf("%s\n%s\n",b,a);
          while(gets(buf))              
          {
               int len=strlen(buf);                         
               if(!len)break;
               for(int i=0;i<len;i++)
               {
                   if(m[buf[i]])
                      buf[i]=m[buf[i]];            
               }
               printf("%s\n",buf);
          }    
          if(t)printf("\n");
    }
    return 0;
}
