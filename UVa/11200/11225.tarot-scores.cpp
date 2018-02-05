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

int needed[] = {560, 510, 410, 360};
char w[500];
char name[500], suit[500];
int special;
int get_value()
{
    gets(w);
    int k = sscanf(w, "%s %*s %s", name, suit);
    if(k == 1)
    {
       ++special;       
       return 45;
    }
    
    if(!strcmp(suit, "trumps") && (!strcmp(name, "twenty-one") || !strcmp(name, "one")))
    {
       special++;
       return 45;
    }
    
    string name_str = string(name, name + strlen(name));
    string suit_str = string(suit, suit + strlen(suit));
    if(name_str == "king")
       return 45;
    if(name_str == "queen")
       return 35;
    if(name_str == "knight")
       return 25;
    if(name_str == "jack")
       return 15;
    return 5;
}

int main()
{   
    int cas, n;
    scanf("%d", &cas);
    F(z, cas)
    {
        if(z)NL; 
        scanf("%d", &n);
        gets(w);
        int sum = 0;
        special = 0;
        for(int i = 0; i < n; ++i)
            sum += get_value();
        
        printf("Hand #%d\n", z + 1);
        if(needed[special] > sum)
           printf("Game lost by %d point(s).", (needed[special] - sum) / 10);
        else
           printf("Game won by %d point(s).", (sum - needed[special]) / 10);
        NL;
    }
    return 0;
}
