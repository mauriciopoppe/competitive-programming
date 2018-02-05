#include <iostream>
#define LEN 32
#define MAX 110
using namespace std;
char a[MAX][LEN],b[MAX][LEN];
int lcs[MAX][MAX];
int pt[MAX];                    //pointer to the letter

int main()
{
    while(scanf("%s",a[0])==1)
    {
          int m=1,n=0;
          while(scanf("%s",a[m]) && a[m][0]!='#')
                lcs[m++][0]=0;

          while(scanf("%s",b[n]) && b[n][0]!='#')
                lcs[n++][0]=0;  
          
          for(int i=0;i<m;i++)
              for(int j=0;j<n;j++)
              {
                      if(strcmp(a[i],b[j])==0)        
                           lcs[i+1][j+1]=lcs[i][j]+1;
                      else if(lcs[i][j+1]>=lcs[i+1][j])
                           lcs[i+1][j+1]=lcs[i][j+1];     
                      else
                           lcs[i+1][j+1]=lcs[i+1][j];    
              }
          
          int i=m,j=n;
          while(i>0 && j>0)
          {
               while(lcs[i][j]==lcs[i][j-1])
                    j--;
               while(lcs[i][j]==lcs[i-1][j])
                    i--;
               pt[lcs[i--][j--]]=i-1;        
          }
          
          if(lcs[m][n] > 0)
              fputs(a[pt[1]],stdout);
        
          for(i = 2; i <= lcs[m][n]; i++)
            putc(32, stdout), fputs(a[pt[i]], stdout);

          putchar(10);                     
    }
}
