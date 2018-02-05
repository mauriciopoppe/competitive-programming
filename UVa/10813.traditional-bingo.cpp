#include<iostream>
using namespace std;

int a[5][5];
int row[5],col[5],d[2];
int num[76];

int main()
{
    int t,f=true,aux=0;
    cin>>t;
    while(t--)
    {
        d[0]=d[1]=1;
        a[2][2]=-1;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        row[2]=1;
        col[2]=1;
        

        f=true;  
        aux=0;    
        for(int i=0;i<5;i++)
        { 
              for(int j=0;j<5;j++)
              {
                   if(f && aux>11){j++;f=false;}
                   cin>>a[i][j];      
                   aux++;
              }
        }
        
        /*
        for(int i=0;i<5;i++)
        {
           for(int j=0;j<5;j++)
           printf("%d ",a[i][j]);
           printf("\n");
           }
        */
        
        for(int i=0;i<75;i++)
           cin>>num[i];
        
        int sol=0;
        for(int k=0;k<75;k++)
        {   
           sol++; 
           for(int i=0;i<5;i++)
               for(int j=0;j<5;j++)
                  if(a[i][j]==num[k])
                    {
                         row[i]++;
                         col[j]++;
                         
                         if(i==j)d[0]++;
                         if(i==4-j)d[1]++;
                         
                         if(row[i]==5 || col[j]==5 || d[0]==5 || d[1]==5)goto l1;    
                         goto l2;            
                    }  
               l2:
                    continue;
        }
        
        l1:
        printf("BINGO after %d numbers announced\n",sol);      
    }    
}
