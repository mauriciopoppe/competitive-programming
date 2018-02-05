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

char letter_c5[][5][7] = {
                          
                  {".***..",
                  "*...*.",
                  "*****.",
                  "*...*.",
                  "*...*."},
                          
                  {"****..",
                  "*...*.",
                  "****..",
                  "*...*.",
                  "****.."},

                 {".****.",
                  "*...*.",
                  "*.....",
                  "*.....",
                  ".****."},

                 {"****..",
                  "*...*.",
                  "*...*.",
                  "*...*.",
                  "****.."},

                 {"*****.",
                  "*.....",
                  "***...",
                  "*.....",
                  "*****."},

                 {"*****.",
                  "*.....",
                  "***...",
                  "*.....",
                  "*....."},

                 {".****.",
                  "*.....",
                  "*..**.",
                  "*...*.",
                  ".***.."},

                 {"*...*.",
                  "*...*.",
                  "*****.",
                  "*...*.",
                  "*...*."},

                 {"*****.",
                  "..*...",
                  "..*...",
                  "..*...",
                  "*****."},

                 {"..***.",
                  "...*..",
                  "...*..",
                  "*..*..",
                  ".**..."},

                 {"*...*.",
                  "*..*..",
                  "***...",
                  "*..*..",
                  "*...*."},

                 {"*.....",
                  "*.....",
                  "*.....",
                  "*.....",
                  "*****."},

                 {"*...*.",
                  "**.**.",
                  "*.*.*.",
                  "*...*.",
                  "*...*."},

                 {"*...*.",
                  "**..*.",
                  "*.*.*.",
                  "*..**.",
                  "*...*."},

                 {".***..",
                  "*...*.",
                  "*...*.",
                  "*...*.",
                  ".***.."},

                 {"****..",
                  "*...*.",
                  "****..",
                  "*.....",
                  "*....."},

                 {".***..",
                  "*...*.",
                  "*...*.",
                  "*..**.",
                  ".****."},

                 {"****..",
                  "*...*.",
                  "****..",
                  "*..*..",
                  "*...*."},

                 {".****.",
                  "*.....",
                  ".***..",
                  "....*.",
                  "****.."},

                 {"*****.",
                  "*.*.*.",
                  "..*...",
                  "..*...",
                  ".***.."},

                 {"*...*.",
                  "*...*.",
                  "*...*.",
                  "*...*.",
                  ".***.."},

                 {"*...*.",
                  "*...*.",
                  ".*.*..",
                  ".*.*..",
                  "..*..."},

                 {"*...*.",
                  "*...*.",
                  "*.*.*.",
                  "**.**.",
                  "*...*."},

                 {"*...*.",
                  ".*.*..",
                  "..*...",
                  ".*.*..",
                  "*...*."},

                 {"*...*.",
                  ".*.*..",
                  "..*...",
                  "..*...",
                  "..*..."},

                 {"*****.",
                  "...*..",
                  "..*...",
                  ".*....",
                  "*****."},

                 {"......",
                  "......",
                  "......",
                  "......",
                  "......"}};

char paper[60][61];

void print_page()
{
     /*for(int i = 0; i < 60; ++i)
         printf("%d", i % 10);NL;*/
         
     for(int i = 0; i < 60; ++i)
     {
         paper[i][60] = '\0';  
         puts(paper[i]);
     }
     NL;
     for(int i = 0; i < 60; ++i)
         putchar('-');
     NL;
     NL;
}

void write_c5(char w[], int row, int col)
{
     int size = strlen(w);
     for(int k = 2; k < size - 1 && col < 60; ++k)
     {
         int letter;
         if(w[k] == ' ')
             letter = 26;
         else
             letter = w[k] - 'A';
         for(int i = 0; i < 5 && row + i < 60; ++i)
            for(int j = 0; j < 6 && col + j < 60; ++j)
               if(j + col >= 0)
                  paper[i + row][j + col] = letter_c5[letter][i][j];         
         col += 6;
     }
}

void write_c1(char w[], int row, int col)
{
     int size = strlen(w);
     for(int i = 2; i < size - 1 && col < 60; ++i, ++col)
     {
        if(col < 0)
           continue;
        if(w[i] != ' ')
           paper[row][col] = w[i];        
     }
}

void solve(char w[])
{
     char font[10];
     int row, col;
     char text[10000];
     if(w[1] == 'C')
     {
         scanf("%s%d", font, &row);
         row--;
         gets(text);
         if(!strcmp(font, "C5"))
         {
            int len = (strlen(text) - 3) * 6;
            write_c5(text, row, 30 - len / 2);
         }
         else
            write_c1(text, row, 30 - (strlen(text) - 3) / 2);
     }
     else if(w[1] == 'P')
     {
         scanf("%s%d%d", font, &row, &col);
         --row, --col;
         gets(text);
         if(font[1] == '5')
            write_c5(text, row, col);
         else
            write_c1(text, row, col);
     }
     else if(w[1] == 'R')
     {
         scanf("%s%d", font, &row);
         row--;
         gets(text);
         if(font[1] == '5')
         {
            int len = (strlen(text) - 3) * 6;
            write_c5(text, row, 60 - len);            
         }      
         else
            write_c1(text, row, 60 - (strlen(text) - 3));
     }
     else
     {
         scanf("%s%d", font, &row);
         row--;
         gets(text);
         if(font[1] == '5')
            write_c5(text, row, 0);
         else
            write_c1(text, row, 0);
     }     
     //print_page();
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char w[500];
    while(scanf("%s", w) != EOF)
    {
        memset(paper, '.', sizeof paper);        
        if(!strcmp(w, ".EOP"))
        {
           print_page();
           continue;
        }
        solve(w);
        while(scanf("%s", w) && strcmp(w, ".EOP"))
            solve(w);
        print_page();
    }
    return 0;
}
