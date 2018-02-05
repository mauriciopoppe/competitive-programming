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
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 1000000


int main()
{
    int t;
    int len,n,k;
    string w;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d%d",&len,&n);
         len*=100;
         queue<int> left,right;
         F(i,n)
         {
               cin>>k>>w;
               if(w=="left")left.push(k);
               else right.push(k);
         }
         //printf("here");
         int c=0,temp;         
         while(1)
         {
               temp=len;
               if(left.empty() && right.empty())break;
               while(!left.empty())
                 if(left.front()<temp)
                    temp-=left.front(),left.pop();
                 else break;                 
               c++;
               
               temp=len;
               if(left.empty() && right.empty())break;
               while(!right.empty())
                 if(right.front()<temp)
                    temp-=right.front(),right.pop();
                 else break;
               c++;
         }
         printf("%d\n",c);
    }
    return 0;
}
