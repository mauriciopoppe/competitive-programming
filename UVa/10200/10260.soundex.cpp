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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
map<char, char> m;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    m['B']=m['F']=m['P']=m['V']='1';
    m['C']=m['G']=m['J']=m['K']=m['Q']=m['S']=m['X']=m['Z']='2';
    m['D']=m['T']='3';
    m['L']='4';
    m['M']=m['N']='5';
    m['R']='6';    
    string w,t;
    while(cin>>w)
    {
         t="";
         int s=w.size();
         char last='0';
         for(int i=0;i<s;i++)
         {
             if(m.find(w[i])!=m.end())
             {                       
                if(last!=m[w[i]])
                {                     
                    t+=m[w[i]];    
                    last=m[w[i]];
                }
             }
             else last='0';
         }
         printf("%s\n",t.c_str());        
    }
    return 0;
}
