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
    //reopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char w[40],e[40],nw[40];
    int c=0,g;
    while(scanf("%s",w)!=EOF)
    {
          while((g=getchar()) && !isalpha(g));
          int i=0;
          e[i++]=g;
          while((g=getchar())!='\n')e[i++]=g;
          e[i]='\0';                   
                             
          if(c)printf("\n");
          c++;                       
          printf("%s (to %s)\n",w,e);
          int len=strlen(w);
          if(len>1 && w[len-1]=='r' && (w[len-2]=='a' || w[len-2]=='e' ||w[len-2]=='i'))
          {
               int i=0;            
               for(i=0;i<len-2;i++)
                  nw[i]=w[i];
               char vow=w[len-2];
               if(vow=='a' || vow=='e')
               {
                    nw[i]='o';
                    nw[i+1]='\0';       
                    printf("eu        %s\n",nw);
                    
                    nw[i++]=vow;
                    nw[i]='s';
                    nw[i+1]='\0';       
                    printf("tu        %s\n",nw);
                    
                    nw[i]='\0';                         
                    printf("ele/ela   %s\n",nw);
                    
                    nw[i]='m';
                    nw[i+1]='o';
                    nw[i+2]='s';
                    nw[i+3]='\0';
                    putchar('n');
                    putchar(243);
                    putchar('s');
                    printf("       %s\n",nw);
                    
                    nw[i]='i';
                    nw[i+1]='s';
                    nw[i+2]='\0';
                    putchar('v');
                    putchar(243);
                    putchar('s');
                    printf("       %s\n",nw);
                    
                    nw[i]='m';
                    nw[i+1]='\0';
                    printf("eles/elas %s\n",nw);       
               }
               
               else
               {
                    nw[i]='o';
                    nw[i+1]='\0';       
                    printf("eu        %s\n",nw);
                    
                    nw[i]='e';
                    nw[i+1]='s';
                    nw[i+2]='\0';       
                    printf("tu        %s\n",nw);
                    
                    nw[i]='e';
                    nw[i+1]='\0';                   
                    printf("ele/ela   %s\n",nw);
                    
                    nw[i]=vow;
                    nw[i+1]='m';
                    nw[i+2]='o';
                    nw[i+3]='s';
                    nw[i+4]='\0';
                    putchar('n');
                    putchar(243);
                    putchar('s');
                    printf("       %s\n",nw);
                    
                    nw[i]=vow;
                    nw[i+1]='s';
                    nw[i+2]='\0';
                    putchar('v');
                    putchar(243);
                    putchar('s');
                    printf("       %s\n",nw);
                    
                    nw[i]='e';
                    nw[i+1]='m';
                    nw[i+2]='\0';
                    printf("eles/elas %s\n",nw);
               }
                           
          }
          else printf("Unknown conjugation\n");                                                    
    }
    return 0;
}
