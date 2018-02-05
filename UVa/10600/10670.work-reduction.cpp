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

struct agency{
       string name;
       int val;
       agency(string a, int b){name=a;val=b;}
       bool operator<(const agency &x)const
       {
            if(x.val!=val)return val<x.val;
            return name<x.name;     
       }};

int main()
{
    int t,M,L,A,a,b,half,left,total;
    char name[20],buf[30];
    scanf("%d",&t);
    vector<agency> v;
    for(int q=1;q<=t;++q)
    {
          v.clear();
          scanf("%d%d%d",&M,&L,&A);
          getchar();
          for(int r=0;r<A;++r)
          {
               left=M;   
               total=0;
               gets(buf);
               for(int i=0;i<20;i++)
                  if(buf[i]==':'){buf[i]=' ';break;}
               sscanf(buf,"%s %d,%d",name,&a,&b);
               while(left>L)
               {
                    //reduce by half  
                    //printf("%d %d\n",left,total);      
                    int half=left/2;
                    if(half>=L)
                    {
                         int y=left-half;
                         int x=a*y;       
                         if(b<x)
                             total+=b,left=half;
                         else total+=x,left-=y;                                     
                    }
                    else 
                         total+=a*(left-L),left=L;                                                                                
               }
               v.push_back(agency(string(name),total));         
          }         
          sort(v.begin(),v.end());
          printf("Case %d\n",q);
          for(int i=0;i<v.size();i++)
             printf("%s %d\n",v[i].name.c_str(),v[i].val);
    }
    return 0;
}
