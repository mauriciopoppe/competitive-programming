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
vector<string> top;
int ans[27], final_ans[27];
int n;
int flag = 0;

int check(int k)
{
    for(int i = 0; top[k][i] != ';'; i += 2)
    {
        int sign_topping = top[k][i] == '-' ? -1 : 1;
        if(ans[top[k][i + 1] - 'A'] == sign_topping)
           return 1;
    }
    return 0;
}

void bt(int k)
{
     if(flag)
         return;
     if(k == n)
         flag = 1, memcpy(final_ans, ans, sizeof ans);
     else
     {
         if(check(k))
             bt(k + 1);
         for(int i = 0; top[k][i] != ';'; i += 2)
         {
             //Check if a the current topping is valid for this req
             if(ans[top[k][i + 1] - 'A'] == 0)  //check only new toppings
             {
                  int sign_topping = top[k][i] == '-' ? -1 : 1;
                  ans[top[k][i + 1] - 'A'] = sign_topping;
                  bt(k + 1);
                  ans[top[k][i + 1] - 'A'] = 0;
             }
         }
     }
}


void solve()
{
    sort(ALL(top));
    //TR(top, it)
    //   printf("> %s\n", it->c_str());
    memset(ans, 0, sizeof ans);
    flag = 0;
    bt(0);
    if(!flag)
       puts("No pizza can satisfy these requests.");
    else
    {
       printf("Toppings: ");
       for(int i = 0; i < 26; ++i)
          if(final_ans[i] == 1)
             putchar(i + 'A');
       NL; 
    }
}

int main()
{
    n = 0;
    string str;
    while(cin >> str)
    {
        top.clear();
        top.push_back(str);      
        if(top[0][0] == '.')
        {
            puts("Toppings: ");
            continue;    
        }
        ++n;
        while(cin >> str && str[0] != '.')
            top.push_back(str), ++n;
        solve();
        n = 0;
    }
    return 0;
}
