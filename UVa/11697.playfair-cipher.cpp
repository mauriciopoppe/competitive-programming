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
#define pii pair<int,int>
char m[5][5];
char key[1050];
char temp[1050];
char encode[1050];
bool letter[26];

void init()
{
    memset(letter, 0, sizeof letter);
    letter['Q' - 'A'] = 1;      
}

int mod5(int n)
{
    while(n >= 5) 
         n -= 5;
    return n;    
}

int main()
{
    int cas;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
         init();       
         gets(key);
         gets(temp);
         
         map<char, pair<int,int> > position;
         
         int next = 0;
         
         //initial fill
         for(int i = 0; key[i]; ++i)
            if(islower(key[i]) && !letter[key[i] - 'a'])
            {
                 letter[key[i] - 'a'] = 1;
                 int row = next / 5;
                 int col = mod5(next);
                 position[toupper(key[i])] = pii(row,col);
                 m[row][col] = toupper(key[i]);
                 ++next;
            }
         
         //filling the res
         for(int i = 0; i < 26; ++i)
            if(!letter[i])
            {
                 int row = next / 5;
                 int col = mod5(next);
                 position[(char)(i + 'A')] = pii(row,col);
                 m[row][col] = (char)(i + 'A');
                 ++next;
            }
         
         /*F(i,5)
         {
            F(j,5)
               printf("%c ",m[i][j]);NL;   
         }*/
         //TR(position, it)
         //  printf("%c %d %d\n",it->first,it->second.first,it->second.second);
         
         int j = 0, i;
         for(i = 0, j = 0; temp[i]; ++i)
            if(islower(temp[i]))
               encode[j++] = temp[i];         
         encode[j] = '\0';
         encode[j + 1] = '\0';
         
         //start encoding
         for(int i = 0; encode[i]; i +=2)
         {
             char x = encode[i];
             char y = encode[i + 1];    
             if(encode[i] == encode[i + 1] || encode[i + 1] == '\0')
             {
                y = 'X';
                --i;
             }
             
             pii F = position[toupper(x)]; 
             pii S = position[toupper(y)]; 
             //printf("[%c %c] %d %d - %d %d\n",encode[i], encode[i+1],F.first, F.second, S.first, S.second);
             //SP;
             //same row
             if(F.first == S.first)
             {
                 int a = mod5(F.second + 1);
                 int b = mod5(S.second + 1);
                 printf("%c%c", m[F.first][a], m[F.first][b]);
             }
             //same column
             else if(F.second == S.second)
             {
                 int a = mod5(F.first + 1);
                 int b = mod5(S.first + 1);
                 printf("%c%c", m[a][F.second], m[b][F.second]);
             }
             else
             {
                 int a = S.second;
                 int b = F.second;
                 printf("%c%c", m[F.first][a], m[S.first][b]);
             }
         }
         NL;
    }
    return 0;
}
