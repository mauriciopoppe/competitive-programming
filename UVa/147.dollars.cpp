#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#define M 6010
using namespace std;
double cc[M];
int coins[11]={1,2,4,10,20,40,100,200,400,1000,2000};

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    memset(cc,0,sizeof(cc));
    cc[0]=1;
    for(int i=0;i<11;i++)
    {
        int c=coins[i];
        for(int j=c;j<=M;j++)
           cc[j]+=cc[j-c];    
    }    
    double d;
    while(1)
    {
            cin>>d;
            if(d==0)break;
            printf("%6.2lf%17.lf\n",d,cc[(int)(d*20)]);
    }
}
