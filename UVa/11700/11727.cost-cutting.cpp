#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,a,b,c;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
         scanf("%d%d%d",&a,&b,&c);
         if(a>b)swap(a,b);
         if(a>c)swap(a,c);
         if(b>c)swap(b,c);
         printf("Case %d: %d\n",i,b);               
    }
    return 0;
}
