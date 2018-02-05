#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<cctype>
using namespace std;

bool isp(string &w)
{
     return equal(w.begin(),w.end(),w.rbegin());     
}

char t[10000],w[10000];
int main()
{
    int cc;
    scanf("%d",&cc);
    getchar();
    for(int q=0;q<cc;q++)
    {
         gets(t);
         int len=strlen(t),j=0;
         for(int i=0;i<len;i++)        
             if(isalpha(t[i]))w[j++]=t[i];
         w[j]='\0';
         string nw(w);
         
         int l2=strlen(w);
         double x=sqrt(l2);             
             
         printf("Case #%d:\n",q+1);
         if(isp(nw) && ceil(x)==floor(x))
             printf("%d\n",(int)(x));
         else
             printf("No magic :(\n");
         
    }
    return 0;
}
