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

struct team{
       string name;
       int a,d;
       team(string x, int y, int z){name=x;a=y;d=z;}
       bool operator<(const team& x)
       const{
             if(a!=x.a)return a>x.a;
             else if(d!=x.d)return d<x.d;
             else return name<x.name;
             }
       };

bool cmp(team a, team b)
{return a.name<b.name;}
int main()
{
    int t,a,d;
    string name;
    scanf("%d",&t);
    for(int q=1;q<=t;q++)
    {
          vector<team> v;
          for(int i=0;i<10;i++)
          {
                cin>>name>>a>>d;
                v.push_back(team(name,a,d));  
          }        
            
          sort(v.begin(),v.end());
          
          sort(v.begin(),v.begin()+5,cmp);
          sort(v.begin()+5,v.end(),cmp);
          
          
          printf("Case %d:\n(",q);
          for(int i=0;i<5;i++)
          {
               if(i)printf(", ");
               printf("%s",v[i].name.c_str());        
          }
          printf(")\n(");
          for(int i=0;i<5;i++)
          {
               if(i)printf(", ");
               printf("%s",v[i+5].name.c_str());        
          }
          printf(")\n");
    }
    return 0;
}
