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
#define M 100000
char code[M][20];
char name[M][30];
double price[M];
int size[M];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int k = 0, i;
    int p, min;
    char w[M];
    while(gets(w) && strcmp(w, "000000"))
    {
        int j = 0;
        for(i = 0; w[i] != ' '; ++i);
        ++i;
        for(; w[i] != '$'; ++i)
            name[k][j++] = w[i];
        name[k][j] = '\0';
        p = 0;
        ++i;
        for(;w[i]; ++i)
           p = p * 10 + w[i] - '0';
        sscanf(w, "%s", code[k]);
        price[k] = double(p) / 100.0;
        size[k] = strlen(code[k]);
        ++k;
    }
    
    /*F(i, k)
       printf("[%s] [%s] %lf %d\n", code[i], name[i], price[i], size[i]); */ 
    /*for(int i = 1; i < 70; ++i)
       printf("%d", i % 10);NL;
    printf("%s%5s%-5s\n", "aaa", "a", "a");*/
    while(scanf("%s", &w) && w[0] != '#')
    {
        char total[M] = {'\0'};
        char minute[M] = {'\0'};
        char city[M] = {'\0'};
        char number[M] = {'\0'};
        
        scanf("%d", &min);
        int s = strlen(w);
        i = 0;
        if(w[0] == '0')
        {
            for(i = 0; i < k; ++i)
                if(s > size[i] && !strncmp(w, code[i], size[i]))
                {
                    int number_len = strlen(w + size[i]); 
                    if(w[1] == '0' && number_len >= 4 && number_len <= 10)
                        break;                    
                    else if(w[1] != '0' && number_len >= 4 && number_len <= 7)
                        break;
                }
            if(i < k)
            {
                sprintf(minute, "%.02lf", price[i]);
                sprintf(total, "%.02lf", price[i] * min);
                strcat(city, name[i]);
                strcat(number, w + size[i]);
            }
            else
            {
                strcat(city, "Unknown");
                strcat(total, "-1.00");
            }
        }
        else
        {
            strcat(total, "0.00");
            strcat(minute, "0.00");
            strcat(city, "Local");
            strcat(number, w);
        }
        
        printf("%-15s %s%*s%5d%6s%7s\n", w, city, 35 - strlen(city), number, min, minute, total);
    }
    return 0;
}
