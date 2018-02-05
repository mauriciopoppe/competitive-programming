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
vector<string> suit[4];
string w;
char s[] = {"SHDC"};
void parse(string w)
{
     stringstream ss(w);
     string buf;
     while(ss >> buf)
     {
          int i;
          for(i = 0; i < 4; ++i)
             if(buf[1] == s[i])
                break;
          suit[i].push_back(buf);
     }
}

int add_points(string &w)
{
    if(w[0] == 'A')return 4;
    if(w[0] == 'K')return 3;
    if(w[0] == 'Q')return 2;
    if(w[0] == 'J')return 1;
    return 0;
}

int subtract_points(vector<string> &v)
{
    //find king
    int i = 0, size = v.size();
    int sub = 0;
    for(i = 0; i < size; ++i)
       if(v[i][0] == 'K')
          break;
    if(i != size && size == 1)
       ++sub;
       
    for(i = 0; i < size; ++i)
       if(v[i][0] == 'Q')
          break;
    if(i != size && size <= 2)
       ++sub;
    
    for(i = 0; i < size; ++i)
       if(v[i][0] == 'J')
          break;
    if(i != size && size <= 3)
       ++sub;       
    return sub;     
}

int check_stopped(int k)
{
    int size = suit[k].size();
    int i;
    for(i = 0; i < size; ++i)
       if(suit[k][i][0] == 'A')
          break;
    if(i != size)
       return 1;
    
    for(i = 0; i < size; ++i)
       if(suit[k][i][0] == 'K')
          break;
    if(i != size && size >= 2)
       return 1;
    
    for(i = 0; i < size; ++i)
       if(suit[k][i][0] == 'Q')
          break;
    if(i != size && size >= 3)
       return 1;
    return 0;
}

int extra_points(int i)
{
    int size = suit[i].size();
    if(size == 2)return 1;
    if(size == 1)return 2;
    if(size == 0)return 2;
    return 0;    
}

string solve()
{
    int sum = 0;  
    //initial points
    for(int i = 0; i < 4; ++i)
        TR(suit[i], it)
            sum += add_points(*it);
    //subtract points
    for(int i = 0; i < 4; ++i)
        sum -= subtract_points(suit[i]);
    //printf("%d\n", sum);
    if(sum >= 16)
    {
        int stopped = 0;
        for(int i = 0; i < 4; ++i)
            stopped += check_stopped(i);
        if(stopped == 4)
            return "BID NO-TRUMP";
    }
    
    //extra points
    for(int i = 0; i < 4; ++i)
       sum += extra_points(i);
    
    if(sum < 14)
       return "PASS";
       
    int best = 0;
    for(int i = 1; i < 4; ++i)
       if(suit[i].size() > suit[best].size())
          best = i;
    
    string winner = "BID ";
    winner += s[best];
    //cout << winner <<endl;
    return winner;
}

int main()
{
    while(getline(cin, w))
    {
         suit[0].clear();
         suit[1].clear();
         suit[2].clear();
         suit[3].clear();
         parse(w);
         printf("%s\n", solve().c_str());
    }
    return 0;
}
