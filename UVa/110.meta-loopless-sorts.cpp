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
char w[10];
char t[50];
char spaces[31];
int n;
char* writeline()
{     
     int size = 0;
     for(int i = 0; i < n; ++i)
     {
        if(i)t[size++] = ',';    
        t[size++] = w[i];
     }
     t[size] = '\0';
     return t;
}

void solve(int n_spaces, int start)
{
     if(start == n)
         printf("%swriteln(%s)\n", spaces + 30 - n_spaces, writeline());
     else
     {
         int i = start - 1;
         while(1)
         {
             if(i == start - 1)
                printf("%s", spaces + 30 - n_spaces);
             printf("if %c < %c then\n", w[i], w[i + 1]);
             
             solve(n_spaces + 2, start + 1);
             swap(w[i], w[i + 1]);

             printf("%selse%s", spaces + 30 - n_spaces, i == 0 ? "\n" : "");             
             if(i == 0)     
             {                     
                  solve(n_spaces + 2, start + 1);        
                  char temp = w[0];
                  for(int i = 0; i < start; ++i)
                     w[i] = w[i + 1];
                  w[start] = temp;
                  break;
             }
             else
                putchar(' ');
             --i;
         }
     }
}

int main()
{
    int cas;
    scanf("%d", &cas);
    memset(spaces, ' ', sizeof spaces);
    spaces[30] = '\0';
    while(cas--)
    {
        scanf("%d", &n);           
        puts("program sort(input,output);");
        puts("var");
        for(int i = 0; i < n; ++i)
        {
            if(i)putchar(',');
            printf("%c", i + 'a');    
            w[i] = i + 'a';
        }
        puts(" : integer;");
        puts("begin");
        printf("  readln(");
        for(int i = 0; i < n; ++i)
        {
            if(i)putchar(',');
            printf("%c", i + 'a');    
        }
        puts(");");
        solve(2, 1);
        puts("end.");
        if(cas)NL;        
    }
    return 0;
}
