#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
int a,b,cas,c,p,x;
scanf("%d",&cas);
while(cas--)
{
scanf("%d%d",&a,&b);
if(b==0)
{
printf("1\n");
}
else if(a==0||a%10==0)
{
printf("0\n");
}
else
{
p=a%10;
a=1;
int bs[10],cc[10];
memset(bs,0,sizeof bs);            
c=1;
while(!bs[x=(a*p)%10])                
cc[c++]=x, bs[a=x]=1;
cc[0]=cc[--c];
printf("%d\n",cc[b%c]);
}
}
return 0;
}
