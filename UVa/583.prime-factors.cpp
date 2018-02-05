#include<iostream>
#include<bitset>
#define TOP 46500
#define SIZE (TOP-3)/2
 
using namespace std;
long long n;

bitset<SIZE+1> bset;
long long q[SIZE+1];

void genPrimes()
{
    int i,j;
    for(i=0;i*i<=SIZE;i++)
        if(!bset.test(i))
             for(j=i+1;(2*j+1)*(2*i+3)<=SIZE;j++)
                  bset.set(((2*j+1)*(2*i+3)-3)/2);
    q[0]=2;
    for(i=1,j=0;j<SIZE+1;j++)
       if(!bset.test(j))
          q[i++]=2*j+3;         
}

int main()
{
    long long n;
    int f;
    genPrimes();
    while(1)
    {
            cin>>n;
            if(n==0)break;
            printf("%lld = ",n);
            f=1;
            if(n<0)
            {
                   printf("-1 x ");
                   n=-n;       
            }
            else
            {
                   
            }
            
            for(int i=0;q[i]*q[i]<=n;i++)
            {
                while(n%q[i]==0)
                {
                     if(f)f=0;
                     else printf(" x ");
                     printf("%d",q[i]);
                     n/=q[i];                   
                }       
            }
            
            if(!f && n!=1)printf(" x ");
            if(n>1)
                  printf("%lld",n);
            printf("\n");
    }    
}
