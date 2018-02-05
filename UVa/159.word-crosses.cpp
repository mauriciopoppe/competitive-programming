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
#define M 12
using namespace std;

char w[25][30];

int main()
{
    char a[M],b[M],c[M],d[M];
    int i,j,k,L,sa,sb,sc,sd,mx,cc=0;
    while(scanf("%s",a) && strcmp(a,"#")!=0)
    {
         if(cc)printf("\n");
         ++cc;               
         memset(w,' ',sizeof(w));
         for(i=0;i<25;i++)
            w[i][29]='\0';
                        
         scanf("%s %s %s",b,c,d);
         //printf("%s %s %s %s\n",a,b,c,d);
         //first
         sa=strlen(a);
         sb=strlen(b);
         for(i=0;i<sa;i++)
            for(j=0;j<sb;j++)
               if(a[i]==b[j])goto l1;
         l1:
         if(i==sa)
         {
                 printf("Unable to make two crosses\n");        
                 continue;
         }
         //second                           
         sc=strlen(c);
         sd=strlen(d);
         for(k=0;k<sc;k++)
            for(L=0;L<sd;L++)
               if(c[k]==d[L])goto l2;
         l2:
         if(k==sc)
         {
                 printf("Unable to make two crosses\n");        
                 continue;
         }
         //printf("%d %d %d %d\n",i,j,k,L);
         
         //check whic word starts first
         if(j>=L)
         {   
             mx=max(sb,sd+j-L);          
             //first
             strcpy(w[j],a);
             w[j][sa]=' ';
             for(int x=0;x<sb;x++)
                w[x][i]=b[x];
             sa+=3;
             
             //second
             k=k+sa;
             for(int x=sa,y=0;y<sc;x++,y++)
                w[j][x]=c[y];
                
             for(int x=j-L,y=0;y<sd;x++,y++)
                w[x][k]=d[y];
         }              
         else
         {
             mx=max(sd,sb+L-j);
             //first
             strcpy(w[L],a);
             w[L][sa]=' ';
             
             for(int x=L-j,y=0;y<sb;x++,y++)
                w[x][i]=b[y];
             sa+=3;

             //second
             k=k+sa;
             for(int x=sa,y=0;y<sc;x++,y++)
                w[L][x]=c[y];

             for(int y=0;y<sd;y++)
                w[y][k]=d[y];

         }
         
         int length=sa+sc+2;
         for(i=0;i<mx;i++)
         {
             for(j=length;j>=0 && !isupper(w[i][j]);j--)
             w[i][j]='\0';        
         }
         
         for(int x=0;x<mx;x++)
            if(strlen(w[x])!=0)printf("%s\n",w[x]);
    }
    return 0;
}
