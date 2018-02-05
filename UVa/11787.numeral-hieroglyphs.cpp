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

map<char,int> test;
map<char,int> value;
int cnt[100];

int solve(string &w)
{    
    int size = w.size(); 
    if(size > 9 && test[w[0]] == test[w[size - 1]])
       return -1;
    
    if(test[w[0]] > test[w[size - 1]])
       reverse(w.begin(), w.end());
    
    memset(cnt, 0, sizeof cnt);
    char last = w[0];
    cnt[w[0]]++;
    for(int i = 1; i < size; )
    {
        while(i < size && w[i] == last)
        {
             cnt[last]++;
             if(cnt[last] > 9)
                return -1;
             ++i;
        }
        if(i < size && test[w[i - 1]] > test[w[i]])
           return -1;
        last = w[i];
    }
    return cnt['B'] * value['B'] + 
           cnt['U'] * value['U'] +
           cnt['S'] * value['S'] + 
           cnt['P'] * value['P'] + 
           cnt['F'] * value['F'] + 
           cnt['T'] * value['T'] + 
           cnt['M'] * value['M'];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    test['B'] = 1, test['U'] = 2, test['S'] = 3, test['P'] = 4, test['F'] = 5, test['T'] = 6, test['M'] = 7;
    value['B'] = 1, value['U'] = 10, value['S'] = 100, value['P'] = 1000, 
    value['F'] = 10000, value['T'] = 100000, value['M'] = 1000000;
    
    string w;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        cin >> w;
        int k = solve(w);
        if(k > 0)      
           printf("%d\n",k);
        else 
           printf("error\n");
    }
    return 0;
}
