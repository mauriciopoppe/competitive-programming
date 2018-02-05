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

int main()
{
    int t,a,b;
    map<pair<int,int>, int> m;
    map<pair<int,int>, int>::iterator it;
    pair<int,int> aux;
    while(scanf("%d",&t) && t)
    {
         m.clear();                
         int s=2*t;
         int i=0;                
         for(;i<s;i+=2)
         {
              scanf("%d %d",&a,&b);
              if(a>b)swap(a,b);
              aux=make_pair(a,b);
              it=m.find(aux);
              if(m.find(aux)==m.end())
                  m.insert(make_pair(aux,1));
              else
                  (it->second)++;
         }
         
         //printf("%d\n",m.size());
         
         for(it=m.begin();it!=m.end();it++)
           if(it->second%2!=0)break;
         
         if(it==m.end())printf("YES\n");
         else printf("NO\n");

    }
    return 0;
}
