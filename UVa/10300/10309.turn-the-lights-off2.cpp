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
int m[10][10],n[10][10];
int perm[1030][10];
int nper=0,aux=0;

void print()
{
     for(int i=0;i<10;i++)
        {for(int j=0;j<10;j++)
           printf("%d",m[i][j]);printf("\n");}     
}

void reset()
{
    for(int i=0;i<10;i++)
       for(int j=0;j<10;j++)
          m[i][j]=n[i][j];      
}

void gen(int c, bool b[])
{
     if(c==10)     
     {
           for(int i=0;i<c;i++)
              perm[nper][i]=b[i];
           nper++;         
     }
     else
     {
           b[c]=0;
           gen(c+1,b);
           b[c]=1;
           gen(c+1,b);  
     }
}

void auxPress(int i, int j)
{
     if(m[i][j])m[i][j]=0;
     else m[i][j]=1; 
}

void press(int &i, int &j)
{
     auxPress(i,j);
     if(i-1>=0)auxPress(i-1,j);
     if(j-1>=0)auxPress(i,j-1);
     if(i+1<10)auxPress(i+1,j);
     if(j+1<10)auxPress(i,j+1);          
}

void pressFirst(int &i)
{
     for(int j=0;j<10;j++)
        if(perm[i][j])
          press(aux,j);
}

int main()
{
    bool b[10];
    gen(0,b);
    
    char q[100];
    char c;
    int x,y,best,f;
    while(scanf("%s",q) && strcmp(q,"end")!=0)
    {
         int M=2147483647;       
         //printf("here");        
         for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
               {
                    if(scanf("%c",&c) && c!='\n')
                    {
                        if(c=='O')m[i][j]=n[i][j]=1;
                        else m[i][j]=n[i][j]=0;
                    }else j--;
               }

         for(int k=0;k<nper;k++)
         {
               reset();       
               pressFirst(k);
               
               /*
               printf("START\n");
               print();
               system("pause");
               */
               
               //count number of permutations on the first row
               int ns=0;
               for(int i=0;i<10;i++)
                  if(perm[k][i])ns++;
               
               //switch the remaining lamps
               for(int i=1;i<10;i++)
                  for(int j=0;j<10;j++)
                     if(m[i-1][j])
                       {
                           press(i,j);
                           ns++;
                           //print();
                           //system("pause");
                       }
               f=1;        
               for(int i=0;i<10;i++)
                  if(m[9][i]){f=0;break;}
               if(ns<M && f)M=ns;
         }
         printf("%s %d\n",q,M);
    }     
    return 0;
}
