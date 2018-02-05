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

void parse(string &w)
{
     while(w[0]==' ')w=w.substr(1);
     while(w[w.size()-1]==' ')w=w.substr(0,w.size()-1);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    string w,temp;
    scanf("%d",&t);
    getline(cin,temp);
    F(q,t)
    {
        if(q)NL;  
        getline(cin,temp);
        getline(cin,w);
        parse(w);        
        //printf("[%s]\n",w);
        int len=w.size();
        int j=0,i=0;
        for(i=1;i*2<=len;i++)
        {
             string x=string(w.begin(),w.begin()+i);
             //printf("%s = ",x.c_str());
             for(j=0;j<len;j+=i)
             {
                  string y=string(w.begin()+j,w.begin()+j+i);
                  //printf("[%s]",y.c_str());             
                  if(x!=y)break;
             }
             //NL;NL;
             if(j>=len)break;
        }        
        if(i*2<=len)printf("%d\n",i);
        else printf("%d\n",len);
    }    
    return 0;
}
