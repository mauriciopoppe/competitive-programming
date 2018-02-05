#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int a[2001],lis[2001],lds[2001];
int main()
{
    int q,n,t;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[n-i-1]);
        fill(lis,lis+n,1);
        fill(lds,lds+n,1);
        for(int i=0;i<n-1;i++)
           for(int j=i+1;j<n;j++)
           {
               if(a[i]<a[j] && lis[i]+1>lis[j])lis[j]=lis[i]+1;
               if(a[i]>a[j] && lds[i]+1>lds[j])lds[j]=lds[i]+1;                           
           }      
        
        for(int i=0;i<n;i++)printf("%d ",lis[i]);printf("\n");
        for(int i=0;i<n;i++)printf("%d ",lds[i]);printf("\n");
        int mx=0;
        for(int i=0;i<n;i++)mx>?=(lis[i]+lds[i]-1);
        printf("%d\n",mx);
    }
    //system("pause");

    return 0;
}
