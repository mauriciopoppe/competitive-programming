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

int encode(string s)
{
    if(s=="+y") return 0;
    if(s=="-y") return 1;
    if(s=="+z") return 2;
    if(s=="-z") return 3;
}

string decode(int n)
{
    if(n==0)return "+y";
    if(n==1)return "-y";
    if(n==2)return "+z";
    if(n==3)return "-z";
    if(n==4)return "+x";
    if(n==5)return "-x";
}
int main()
{
    int move[6][4]={{5,4,0,0},
                    {4,5,1,1},
                    {2,2,5,4},
                    {3,3,4,5},
                    {0,1,2,3},
                    {1,0,3,2}};
    int n;
    while(scanf("%d", &n) && n)
    {
         int s = 4;
         string in;
         for(int i = 1; i < n; ++i)
         {
             cin >> in;
             if(in != "No")
                s=move[s][encode(in)];          
         }
         cout << decode(s) << endl;
    }
    return 0;
}
