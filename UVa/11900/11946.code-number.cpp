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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    char w[5000];
    scanf("%d", &cas);    
    gets(w);
    while(cas--)
    {
        while(gets(w) && strlen(w))
        {
            for(int i = 0; w[i]; ++i)
               if(w[i] == '1') w[i] = 'I';
               else if(w[i] == '2') w[i] = 'Z';          
               else if(w[i] == '3') w[i] = 'E';
               else if(w[i] == '4') w[i] = 'A';
               else if(w[i] == '5') w[i] = 'S';
               else if(w[i] == '6') w[i] = 'G';
               else if(w[i] == '7') w[i] = 'T';
               else if(w[i] == '8') w[i] = 'B';
               else if(w[i] == '9') w[i] = 'P';
               else if(w[i] == '0') w[i] = 'O';
            puts(w);
        }
        if(cas)NL;
    }
    return 0;
}
