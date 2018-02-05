#include<iostream>
#include<bitset>
#include<stdlib.h>
using namespace std;
bitset<20> b;

void print(int n)
{
 for(int i=0;i<n;i++)
     cout<<b[i];     
}

void set(int n)
{
     for(int i=0;i<n;i++)     
             b.set(i);
}

void moveK(int *ik, int k, int n)
{
     while(k)
     {
         *ik=(*ik+1)%n;
         //printf("ik=%d\n",*ik);
         if(b.test((int)*ik))
             k--;
     }   
}

void moveM(int *im, int m, int n)
{
     while(m)
     {
         *im=(*im-1<0)? *im-1+n : *im-1 ;
         if(b.test((int)*im))
             m--;
     }   
}

void nextK(int *ik, int n)
{
     while(1)     
     {
         *ik=(*ik+1)%n;        
         if(b.test((int)*ik))return;     
     }
}

void nextM(int *im, int n)
{
     while(1)     
     {
         *im=(*im-1<0)? *im-1+n : *im-1 ;
         if(b.test((int)*im))return;     
     }
}

int main()
{
    int n,k,m;
    bool f=false;
    while(cin>>n>>k>>m)
    {
       if(n+k+m==0)break;  
       b.reset();                 
       set(n);
       k-=1;
       m-=1;
       int ik=0,im=n-1;
       //printf("%d %d %d\n",ik,im,b.count());
       while(b.any())
       {
          moveK(&ik,k,n);            
          //printf("%d\n",ik);   
          moveM(&im,m,n);
          //printf("%d %d\n",ik,im);
          b.flip(ik);         
          if(b.test(im))b.flip(im);
          
          if(ik!=im)printf("%3d%3d",ik+1,im+1);
          else printf("%3d",ik+1);
          
              if(b.none())break;
          printf(",");
          nextK(&ik,n);
          nextM(&im,n);
          //printf("Next -  %d %d\n",ik,im);
          //system("pause");
       }              
       cout<<endl;                
    } 
    return 0;      
}
