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

int main()
{
    string a, b;
    while(getline(cin,a) && getline(cin,b))
    {
        int x=0,y=0;
        int sa=a.size(),sb=b.size();
        for(int i=0;i<sa;i++)
        {
            if(isalpha(a[i]))
            {
                if(islower(a[i]))x+=a[i]-'a'+1;
                else x+=a[i]-'A'+1;             
            }    
        }
        
        for(int i=0;i<sb;i++)
        {
            if(isalpha(b[i]))
            {
                if(islower(b[i]))y+=b[i]-'a'+1;
                else y+=b[i]-'A'+1;             
            }    
        }            
        
        if(x+y==0){printf("\n");continue;       }
        
        //printf("%d %d\n",x,y);
        
        int x1=0,y1=0;
        while(1)
        {
            while(x)
            {
                x1+=x%10;
                x/=10;    
            }
            if(x1>9)x=x1,x1=0;
            else break;
        }
        
        while(1)
        {
            while(y)
            {
                y1+=y%10;
                y/=10;    
            }
            if(y1>9)y=y1,y1=0;
            else break;
        }
        
        if(x1>y1)printf("%.2lf %c\n",((double)y1*100.0)/(double)x1,'%');
        else printf("%.2lf %c\n",((double)x1*100.0)/(double)y1,'%');
        
    }
    return 0;
}
