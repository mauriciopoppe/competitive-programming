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
#define M 60
char suit[] = {"SHDC"};
char rank[] = {"A23456789TJQK"};
int deck[M];
char w[M];
char x[3];

int get_value(char w[])
{
    int i = 0, j = 0;
    for(i = 0; i < 4; ++i)
       if(suit[i] == w[0])
          break;    
    for(j = 0; j < 13; ++j)
       if(rank[j] == w[1])
          break;    
    return i * 13 + j;
}

void get_name(int k)
{
    x[0] = suit[k / 13];
    x[1] = rank[k % 13];
    x[2] = '\0';
}


int check_card(int k)
{
    if(k == 0 || k == 13 || k == 26 || k == 39)
         return 4;
    if(k == 10 || k == 23 || k == 36 || k == 49)
         return 1;
    if(k == 11 || k == 24 || k == 37 || k == 50)
         return 2;
    if(k == 12 || k == 25 || k == 38 || k == 51)
         return 3;
    return 0;
}

deque<int> p[2];

int solve()
{
    //game starts
    deque<int> dealed;
    int i = 0, j;
    
    /*for(int i = 0; i < 26; ++i)
       printf("%d ", p[0][i]);NL;
    for(int i = 0; i < 26; ++i)
       printf("%d ", p[1][i]);NL;*/
    
    while(1)
    {
        //normal play
        while(1)
        {
            if(p[i].size())
            {
                dealed.push_back(p[i].back());
                
                /*get_name(p[i].back());
                puts(x);
                SP;    */

                p[i].pop_back();
                if(check_card(dealed.back()))
                    break;           
                i = !i;
            }
            else
                return !i;
        }
        
        //special play
        while(1)
        {
            j = !i;
            int k;
            int number_cards = check_card(dealed.back());
            for(k = 0; k < number_cards; ++k)
            {
                if(p[j].size())
                {
                    dealed.push_back(p[j].back()); 
                    p[j].pop_back(); 
                    if(check_card(dealed.back()))
                       break;                                        
                }
                else
                    return i;
            }
            if(check_card(dealed.back()))
                i = j;
            else if(k == number_cards)
                break;                
        }
        
        while(dealed.size())
        {
            p[i].push_front(dealed.front());
            dealed.pop_front();
        }
    }
    return 0;
}

int main()
{
    while(1)
    {
        p[0].clear();
        p[1].clear();    
        for(int i = 0; i < 52; ++i)
        {
            scanf("%s", w);
            if(!i && w[0] == '#')
               return 0;
            p[i % 2].push_back(get_value(w));  
        }
        
        int winner = solve();
        if(winner == 0)
           winner = 2;
        printf("%d%3d\n", winner, max(p[0].size(), p[1].size()));
    }
    return 0;
}
