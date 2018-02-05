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

int main()
{
    int n;
    char w[500];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
         gets(w);
         stack<char> s;
         for(int i=0;w[i];++i)
            if(isalpha(w[i]))putchar(w[i]);
            else if(w[i]=='+' || w[i]=='-' || w[i]=='*' || w[i]=='/' || w[i]=='^') s.push(w[i]);
            else if(w[i]==')')putchar(s.top()), s.pop();
         //while(!s.empty())putchar(s.top()), s.pop();
         NL;              
    }
    return 0;
}
