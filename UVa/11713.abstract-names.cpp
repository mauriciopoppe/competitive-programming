#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isvowel(int c)
{
     if(c==97 || c==101 || c==105 || c==111 || c==117)return 1;
     return 0;     
}

int main()
{
    int n;
    char a[25],b[25];
    scanf("%d",&n);
    for(n--;n>=0;n--)
    {
         scanf("%s%s",a,b);
         int s=strlen(a);
         if(s!=strlen(b))printf("No\n");
         else
         {
         int i;
         for(i=0;i<s;i++)
             if(a[i]!=b[i] && (!isvowel(a[i]) || !isvowel(b[i])))
                           break;
         if(i==strlen(a))printf("Yes\n");
         else printf("No\n");                 
         }            
    }  
}
