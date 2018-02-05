#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

char s[1500], t[1500];
char ss[1200][30], tt[1200][30];
int v[1200][1200];
int lenss, lentt;

int LCS()
{
int i, j;
memset(v, 0, sizeof(0));
for(i = 1; i <= lenss; i++)
{
    for(j = 1; j <= lentt; j++)
    {
     if(!strcmp(ss[i], tt[j]))
     {
      v[i][j] = v[i-1][j-1] + 1;
     }
     else
     {
      v[i][j] = max(v[i-1][j], v[i][j-1]);
     }
    }
}
return v[lenss][lentt];
}

int main()
{
int i, j, flag = 1;
while(gets(s) && gets(t))
{
    printf("%2d. ", flag++);
    int lens = strlen(s);
    int lent = strlen(t);
    if(lens == 0 || lent == 0)
    {
     printf("Blank!\n");
     continue;
    }
    for(i = 0; i < lens; i++)
    {
     if(!isalnum(s[i]))
     {
      s[i] = ' ';
     }
    }
    for(i = 0; i < lent; i++)
    {
     if(!isalnum(t[i]))
     {
      t[i] = ' ';
     }
    }
    char *p;
    char *pp = {" "};
    p = strtok(s, pp);
    i = 1;
    while(p != NULL)
    {
     strcpy(ss[i], p);
     p = strtok(NULL, pp);
     i++;
    }
    lenss = i - 1;
    p = strtok(t, pp);
    i = 1;
    while(p != NULL)
    {
     strcpy(tt[i], p);
     p = strtok(NULL, pp);
     i++;
    }
    lentt = i - 1;
    printf("Length of longest match: %d\n", LCS());
}
return 0;
}
