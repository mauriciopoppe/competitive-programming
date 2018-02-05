#include<stdio.h>
#include<string.h>
char a[101],b[101];
int lcs[101][101];

int main()
{
    int cases=1,i,j;
    while(gets(a) && a[0]!='#')
    {
         gets(b);
         int m=strlen(a);
         int n=strlen(b);
         
         for(i=1;i<=m;i++)
             lcs[i][0]=0;
         
         for(j=0;j<=n;j++)
             lcs[0][j]=0;
             
         for(i=0;i<m;i++)
            for(j=0;j<n;j++)
               if(a[i]==b[j])lcs[i+1][j+1]=lcs[i][j]+1;
               else lcs[i+1][j+1]=lcs[i][j+1]>=lcs[i+1][j]?lcs[i][j+1]:lcs[i+1][j];
         
         printf("Case #%d: you can visit at most %d cities.\n",cases++,lcs[m][n]);                
    }   
    return 0;
}
