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

char w[11][11];

void print()
{
     for(int i=0;i<10;i++)
        {for(int j=0;j<10;j++)
           printf("%c",w[i][j]);printf("\n");}     
}

void turn(int i, int j)
{
     if(w[i][j]=='O')w[i][j]='#';
     else w[i][j]='O';
}

bool findon()
{
     for(int i=0;i<10;i++)
       for(int j=0;j<10;j++)
         if(w[i][j]=='O')return true;
     return false;     
}

int main()
{
    char q[100];
    int x,y,best,f=0;
    while(scanf("%s",q) && strcmp(q,"end")!=0)
    {
         for(int i=0;i<10;i++)
            scanf("%s",w[i]);
         
         int tt=0;
         while(findon())                    
         {
              x=y=-1;                             
              best=1;
              f=0; 
              for(int i=0;i<10;i++)
                 for(int j=0;j<10;j++)
                    if(w[i][j]=='O')
                    {
                         int t=1;           
                         if(i-1>=0 && w[i-1][j]=='O')t++;
                         if(j-1>=0 && w[i][j-1]=='O')t++;
                         if(i+1<10 && w[i+1][j]=='O')t++;
                         if(j+1<10 && w[i][j+1]=='O')t++;
                         
                         if(t==5)
                         {
                                turn(i,j);        
                                turn(i-1,j);
                                turn(i,j-1);
                                turn(i+1,j);
                                turn(i,j+1);
                                tt++;
                         }        
                    }
                    
              for(int i=0;i<10;i++)
                 for(int j=0;j<10;j++)
                    {
                         int t=1;           
                         if(i-1>=0 && w[i-1][j]=='O')t++;
                         if(j-1>=0 && w[i][j-1]=='O')t++;
                         if(i+1<10 && w[i+1][j]=='O')t++;
                         if(j+1<10 && w[i][j+1]=='O')t++;
                         if(t>best)
                         {
                             best=t;
                             x=i;
                             y=j;          
                         }
                    } 
                    
               printf("%d -------------\n",tt);
               print();
               printf("best %d x=%d y=%d\n",best,x,y);
               if(best!=1)
               {     
                   turn(x,y);        
                   if(x-1>=0)turn(x-1,y);
                   if(y-1>=0)turn(x,y-1);
                   if(x+1<10)turn(x+1,y);
                   if(y+1<10)turn(x,y+1);   
                   tt++;                           
               }
               printf("%d *************\n",tt);
               print();
               system("pause");
         }      
         printf("%s %d\n",q,tt);
                  
    }
    
    return 0;
}
