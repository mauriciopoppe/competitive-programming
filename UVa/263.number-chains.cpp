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

int x[10],y[10];
int main()
{
    int a,b,cl,c;
    char w[100];
    map<int,int> m;
    while(scanf("%s",&w) && strcmp(w,"0")!=0)
    {
          m.clear();               
          cl=0;
          printf("Original number was %s\n",w);
          do
          {             
              memset(x,0,sizeof(x));               
              int len=strlen(w);                     
              for(int i=0;i<len;i++)
                  x[w[i]-'0']++;                  
              
              a=b=0;
              memcpy(y,x,sizeof(x));
              
              for(int i=9;i>=0;i--)
                 while(x[i]--)a=a*10+i; 
                 
              for(int i=0;i<10;i++)
                 while(y[i]--)b=b*10+i;    
              
              c=a-b;
              m[c]++;
              printf("%d - %d = %d\n",a,b,c);
              ++cl;
              sprintf(w,"%d",c);
          }while(m[c]<2);
          printf("Chain length %d\n\n",cl);
    }
    return 0;
}
