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
typedef long long LL;
struct num{
       LL u,d;
       num(LL a, LL b){u=a;d=b;}
       
       friend bool operator <(num &a, num &b)
       {
              if((LL)(a.u*b.d)<(LL)(a.d*b.u))return true;
              return false;
       }
       
       friend bool operator==(const num &a,const num &b)
       {
              if((LL)(a.u*b.d)==(LL)(a.d*b.u))return true;
              return false;
       }
       
       };

int main()
{
    char w[10000];
    LL u,d,i;
    while(scanf("%lld %lld",&u,&d))
    {    
         num down(0,1), up(1,1), nn(1,2), search(-1,-1);
         if(u==1 && d==1)break;                 
         i=0;
         int f=0;                     
         if(u>d)
         {
             swap(u,d);
             f=1;
         }
         w[i++]='L';
         
         search.u=u;
         search.d=d;
         while(1)
         {
             if(nn==search)break;
              
             if(nn<search)    
             {
                  down.u=nn.u;
                  down.d=nn.d;
                  nn.u=up.u+nn.u;
                  nn.d=up.d+nn.d;      
                  w[i++]='R';
             }  
             else
             {
                  up.u=nn.u;
                  up.d=nn.d;
                  nn.u=down.u+nn.u;
                  nn.d=down.d+nn.d; 
                  w[i++]='L';
             }
         }          
         
         w[i]='\0';
         if(f)
         {
              for(int k=0;k<i;k++)
                 if(w[k]=='L')w[k]='R';
                 else w[k]='L';     
         }         
         printf("%s\n",w);
    }
    return 0;
}
