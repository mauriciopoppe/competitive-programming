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
int n;
bitset<100000> b;
bitset<10> b1;
char word[11];

int candidates(int a[],int w[],int c)
{
    int count=0;
    int i=0;
    for(;i<10;i++)
    {
         int sol=1;   
         for(int j=0;j<c;j++)        
             if(a[j]==i){sol=0;break;}
         if(sol)w[count++]=i;   
    }
    return count;
}

void bt(int c,int a[])
{
     if(c==5)
     {
             int num=0;
             for(int i=0;i<5;i++)
                 num=num*10+a[i];
             b.set(num);
             return;
     }
     else
     {
         int w[10];
         int t=candidates(a,w,c);
         
         for(int i=0;i<t;i++)
         {
             //printf("%d %d\n",c,w[i]);
             //system("pause");    
             a[c]=w[i];    
             bt(c+1,a);     
         }                
     }
}

bool ce(int i, int a)
{
     b1.reset();
     sprintf(word,"%05d",i);     
     for(int j=0;j<5;j++)
          b1.set(word[j]-'0');
     
     sprintf(word,"%05d",a);     
     for(int j=0;j<5;j++)
          b1.set(word[j]-'0');
     
     for(int j=0;j<10;j++)
         if(!b1.test(j))return false;    
     return true;     
}

int main()
{
    //freopen("inDiv.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int a[10];
    memset(a,0,sizeof(a));
    bt(0,a);
    
    int x=0;
    while(scanf("%d",&n) && n)
    {                
         if(x)printf("\n");   
         x++;                
         int cc=0;                
         for(int i=0;i<100000;i++)
         {
             if(b[i])
             {
                  int aux=i*n;
                  if(aux<100000 && b.test(aux) && ce(i,aux))        
                     {printf("%05d / %05d = %d\n",aux,i,n);cc++;}   
             }
         }
         if(!cc)printf("There are no solutions for %d.\n",n);                
    }
    return 0;
}
