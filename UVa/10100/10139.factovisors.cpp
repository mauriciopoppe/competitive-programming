#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define BS 46350
using namespace std;
bitset<BS> b;
int q[BS],j;
void primes()
{
     int i;
     for(i=3;i*i<=BS;i+=2)
        if(!b[i])
           for(j=i*i;j<BS;j+=i)
              b[j]=1;
     j=0;
     q[j++]=2;
     q[j++]=3;
     for(i=3;i<BS;i+=2)
        if(!b[i])q[j++]=i;
        
}

int gp(int &n, int e)
{
    int c=0;
    for(int i=e;i>0 && i<=n ;i*=e)
        c+=n/i;
    return c;    
}

int main()
{
    primes();
    map<int,int> m;
    int a,b,c;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
          if(!b)
          {
                printf("0 does not divide %d!\n",a);                        
                continue;
          }
          m.clear();
          c=b;
          //get factors of b
          while(b%2==0)b/=2,m[2]++;
          
          for(int i=0;i<j-1 && q[i]*q[i]<=b;i++)
          {
               while(b%q[i]==0)
               {
                    m[q[i]]++;
                    b/=q[i];        
               }    
          }

          if(b>1)m[b]++;
          map<int,int>::iterator it=m.begin();
          
          for(;it!=m.end();it++)
               if(gp(a,it->first)<m[it->first])break;

          if(it==m.end())printf("%d divides %d!\n",c,a);
          else printf("%d does not divide %d!\n",c,a);                 
          
                                   
    }
    return 0;
}
