#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cctype>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<sstream>
#include<cstdio>
using namespace std;

typedef long long LL;
int m[4001][4];

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        for(int i=0;i<t;i++)
          for(int j=0;j<4;j++)
             scanf("%d",&m[i][j]);
        
        //a b
        map<int,int> a,b;
        for(int i=0;i<t;i++)
           for(int j=0;j<t;j++)
              a[(m[i][0]+m[j][1])]++,b[(m[i][2]+m[j][3])]++;
        
        map<int,int>::iterator it=a.begin();
        map<int,int>::reverse_iterator it1=b.rbegin();
        LL r=0;
        
        while(1)
        {
             if(it->first + it1->first==0)
                 {r+=a[it->first]*b[it1->first];it++;it1++;}
             else if(- it->first > it1->first)it++;
             else it1++;
             //if(it->first > it1->first)break;
             if(it==a.end() || it1==b.rend())break;
        }
        
        printf("%lld\n",r);
                      
    }
    return 0;
}
