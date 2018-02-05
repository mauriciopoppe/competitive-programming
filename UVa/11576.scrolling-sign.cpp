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

string str, last;
int size, number, total_size;

bool check(int j)
{
     int i = size - 1;
     for(;j >= 0; j--)
        if(str[i--] != last[j])
            return false;
     return true;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&size,&number);   
        cin >> str;
        total_size = str.size();
        for(int i = 1, j; i < number; ++i)
        {
             cin >> last;
             for(j = size - 1; j >= 0; j--)   
                if(check(j)) 
                {
                    total_size += size - j - 1;
                    break;         
                }
             if(j < 0)
                 total_size += size;
             str = last;
        }    
        printf("%d\n",total_size);                          
    }
    return 0;
}
