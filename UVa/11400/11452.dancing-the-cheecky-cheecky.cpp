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
    string w;
    int cas;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
         getline(cin, w);
         int size = w.size();
         int mid = size >> 1;
         int i;
         for(i = mid; i >= 0; --i)
         {
            string str = string(w.begin(), w.begin() + i);
            //cout << str << endl;
            int j = 0;
            for(int k = i; j < i; ++k, ++j)
               if(w[k] != str[j])
                  break;
            if(j == i)
               break;
         }
         
         int left = size % i;
         F(j,8)
           printf("%c",w[left]), left = (left + 1) % i;
         printf("...\n");
         
    }
    return 0;
}
