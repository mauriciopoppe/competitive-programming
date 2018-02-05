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
    char a[100000],b[100000];
    int i,j,sa,sb;
    while(scanf("%s%s",a,b)!=EOF)
    {
         i=j=0; 
         sa=strlen(a);
         sb=strlen(b);                       
         for(;j<sb && i<sa;j++)
             if(b[j]==a[i])i++;
         if(i==sa)printf("Yes\n");
         else printf("No\n");                                                     
    }
    return 0;
}
