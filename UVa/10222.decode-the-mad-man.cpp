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
map<char,char> m;
int main()
{   
    m['2']='`';
    m['3']='1';
    m['4']='2';
    m['5']='3';
    m['6']='4';
    m['7']='5';
    m['8']='6';
    m['9']='7';
    m['0']='8';
    m['-']='9';
    m['=']='0';
    m['e']='q';
    m['r']='w';
    m['t']='e';
    m['y']='r';
    m['u']='t';
    m['i']='y';
    m['o']='u';
    m['p']='i';
    m['[']='o';
    m[']']='p';
    m['\\']='[';
    m['d']='a';
    m['f']='s';
    m['g']='d';
    m['h']='f';
    m['j']='g';
    m['k']='h';
    m['l']='j';
    m[';']='k';
    m['\'']='l'; 
    
    m['c']='z';
    m['v']='x';
    m['b']='c';
    m['n']='v';
    m['m']='b';
    m[',']='n';
    m['.']='m';
    m['/']=',';
    string w;
    while(getline(cin,w))
    {
        int s=w.size();
        F(i,s)
          if(m[tolower(w[i])])w[i]=m[tolower(w[i])];
        cout<<w<<endl;
    }
    
    return 0;
}
