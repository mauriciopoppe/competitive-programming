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
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{
    int a, b;
    while(cin>>a>>b)
    {
        if(a+b==0)break;
        int c=0,t=0;
        while(1)
        {
            if(a==0 && b==0)break;    
            //printf("%d %d\n",a%10,b%10);    
            c=(a%10+b%10+c)/10;
            //cout<<c<<endl;
            if(c)t++;
            a/=10;
            b/=10;            
        }
        if(!t)printf("No carry operation.\n");
        else if(t==1)printf("1 carry operation.\n");
        else printf("%d carry operations.\n",t);                       
    }
    return 0;
}
