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
char w[500];
int v[5];
int calories_per_gram[] = {9, 4, 4, 4, 7};
char type[5];

double total, total_fat;

void solve(char w[])
{
    int cal = 0, per = 0;
    sscanf(w, "%d%c %d%c %d%c %d%c %d%c", &v[0], &type[0], &v[1], &type[1], 
                                          &v[2], &type[2], &v[3], &type[3], 
                                          &v[4], &type[4]);
    
    for(int i = 0; i < 5; ++i)
    {
        if(type[i] == '%')
           per += v[i];
        else if(type[i] == 'g') 
           cal += v[i] * calories_per_gram[i];
        else
           cal += v[i];
    }
    
    double food_total = 0.0, food_fat = 0.0;
    
    if(per > 0 && cal > 0)
    {
        int left_per = 100 - per;
        food_total = 100.0 * cal / left_per;
        if(type[0] == '%')
           food_fat = food_total * (double) v[0] / 100.0;
        else if(type[0] == 'g')
           food_fat = (double) v[0] * 9.0;
        else
           food_fat = (double) v[0];
    }
    else
    {
        food_total = cal;
        if(type[0] == 'g')
           food_fat = (double) v[0] * 9.0;
        else
           food_fat = (double) v[0];
    }
    //printf("%lf %lf\n", food_total, food_fat);
    total_fat += food_fat;
    total += food_total;
}

int main()
{
    while(gets(w) && w[0] != '-')
    {
         total = total_fat = 0;
         solve(w);
         while(gets(w) && w[0] != '-')
            solve(w);
         printf("%d%c\n", (int)round(total_fat * 100.0 / total), '%');
    }
    return 0;
}
