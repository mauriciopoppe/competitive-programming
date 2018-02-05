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
#define M 105
int who[M];
bool dead[M];
int k, n;

void init(int n)
{
    F(i, n)
       dead[i] = 0,
       who[i] = i;     
}

int find_next_alive(int start)
{
    int k = start + 1;
    if(k == n) k = 0;
    while(dead[k])
    {
        k++;
        if(k == n) k = 0;
    }
    return k;
}

int find_right(int start, int num)
{
    int next = start;
    while(1)
    {
        if(!dead[next])
        {
            num--;
            if(!num) return next;           
        }
        next++;
        if(next == n)
            next = 0;
        //printf("here");
    }
    return -1;
}

void print_alive()
{
     for(int i = 0; i < n; ++i)
        //if(!dead[i])
           printf("%d ", who[i] + 1);
     NL;
     for(int i = 0; i < n; ++i)
        if(!dead[i]) printf("0 ");
        else printf("1 ");
     NL;     
}

int solve(int s)
{
     int start = s;
     int alive = n;
     while(alive)
     {
          if(alive == 1)
          {
             for(int i = 0; i < n; ++i)
                if(who[i] == 0)
                {
                    if(!dead[i])
                       return 1;
                    return 0;      
                }
             return 0;
          }
          
          //print_alive();
          
          int will_die = find_right(start, k);
          dead[will_die] = 1;
          //printf("killed = %d\n", who[will_die] + 1);
          int next_alive = find_next_alive(will_die);
          int replace = find_right(next_alive, k);
          swap(who[will_die], who[replace]);
          dead[will_die] = 0;
          dead[replace] = 1;
          
          start = find_next_alive(will_die);
          //printf("%d %d %d %d\n", will_die, next_alive, replace, start);
          //print_alive();
          
          //SP;
          alive--;
          
     }
     return 0;
}

int main()
{
    while(scanf("%d%d", &n, &k) && k + n != 0)
    {
        for(int i = 0; i < n; ++i)
        {
            init(n);
            if(solve(i))
            {
               printf("%d\n", i + 1);
               break;
            }
            //SP;   
        }
    }
    return 0;
}
