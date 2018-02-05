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

char name[][13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
char suit[][9] = {"Clubs", "Diamonds", "Hearts", "Spades"};

int n_shuffles;
int shuffle[100][55];
int deck[55];

void init()
{
    F(i, 53)
        deck[i] = i;
}

void apply_shuffle(int k)
{
    int temp[53]; 
    for(int i = 1; i <= 52; ++i)
       temp[i] = deck[shuffle[k][i]];
    for(int i = 1; i <= 52; ++i)
       deck[i] = temp[i]; 
}

void print_deck()
{
    for(int i = 1; i <= 52; ++i)
    {
        int k = deck[i] - 1;
        //printf("%d\n", k);
        printf("%s of %s\n", name[k % 13], suit[k / 13]);
    }                
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    int shuffles_to_apply;
    int k;
    char w[5];
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n_shuffles);
        for(int i = 1; i <= n_shuffles; ++i)
           for(int j = 1; j <= 52; ++j)
              scanf("%d", &shuffle[i][j]);
        
        init();
        //print_deck();
        gets(w);
        while(gets(w) && strlen(w))
        {
           k = atoi(w);
           apply_shuffle(k);
        }
        
        print_deck();
        if(cas)NL;
    }    
    return 0;
}
