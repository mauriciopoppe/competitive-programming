#include<iostream>
#define M 8000
using namespace std;

long long cc[M+10];
int coins[5]={1,5,10,25,50};

int main()
{
    memset(cc,0,sizeof(cc));
    cc[0]=1;
    for(int i=0;i<5;i++)
    {
        int c=coins[i];
        for(int j=c;j<=M;j++)        
            cc[j]+=cc[j-c];
            
        //for(int k=0;k<=26;k++)printf("%2d ",k);printf("\n");
        //for(int k=0;k<=26;k++)printf("%2d ",cc[k]);printf("\n");
        //system("pause");

    }
    
    int n;
    while(cin>>n)
      printf("%lld\n",cc[n]);
    
}
