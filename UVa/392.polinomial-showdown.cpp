#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int a[10];
char w[][5]={"x^8","x^7","x^6","x^5","x^4","x^3","x^2","x",""};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d",&a[0])!=EOF)
    {                                                       
        FOR(i,1,9)scanf("%d",&a[i]);
        int i=0;
        for(;i<9;i++)
           if(a[i]!=0)break;
           
        if(i==9){printf("0\n");continue;}
        
        if(a[i]==1 && i!=8)printf("%s",w[i]);
        else if(a[i]==-1 && i!=8)printf("-%s",w[i]);
        else printf("%d%s",a[i],w[i]);
        
        i++;
        for(;i<9;i++)
        {        
             if(a[i]!=0)
             {
                    if(a[i]>0)printf(" + ");
                    else printf(" - ");
                    
                    if(abs(a[i])==1 && i!=8)printf("%s",w[i]);
                    else printf("%d%s",abs(a[i]),w[i]);
             }
        }        
        NL;
                                
    }
    return 0;
}
