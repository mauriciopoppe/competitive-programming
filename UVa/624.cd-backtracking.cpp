#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;
vector<int> m;
int a[21];
int t,n,mx,c;

void bt(int i, bitset<21> b, int sum)
{
     if(sum>t)return;
     else if(i==n)
     {
          if(sum<=t && sum>mx)
          {
               m.clear();
               for(int i=0;i<n;i++)
               if(b[i])m.push_back(a[i]);
               c=b.count();
               mx=sum;
          }
          else return;
     }
     else
     {
            b[i]=1;
            bt(i+1,b,sum+a[i]);
            b[i]=0;        
            bt(i+1,b,sum);
     }
}

int main()
{
    bitset<21> b;
    while(scanf("%d%d",&t,&n)!=EOF)
    {
         mx=c=0;                     
         for(int i=0;i<n;i++)
            scanf("%d",&a[i]);                     
         b.reset();                   
         bt(0,b,0);
         for(int i=0;i<m.size();i++)
            printf("%d ",m[i]);
         printf("sum:%d\n",mx);
    }    
    return 0;
}
