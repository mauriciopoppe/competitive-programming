#include<stdio.h>
#include<string.h>
char acc[1000][40];
char w[1000][50];
int m[1000];
int main()
{
    int n, i;
    while(scanf("%d", &n) && n)
       gets(acc[n]);       
    gets(acc[n]);

    scanf("%s %d", w[0], &m[0]);
    int total;
    while(strcmp(w[0], "000000"))
    {        
        total = m[0];
        int k = 1;
        while(scanf("%s%d", w[k], &m[k]) && !strncmp(w[k], w[k - 1], 3))
           total += m[k], ++k;
       
        if(total != 0)
        {
             printf("*** Transaction %c%c%c is out of balance ***\n", w[0][0], w[0][1], w[0][2]);
             for(i = 0; i < k; ++i)
             {
                n = (w[i][3] - '0') * 100 + (w[i][4] - '0') * 10 + (w[i][5] - '0');
                printf("%d %s %*.2lf\n", n, acc[n], 40 - strlen(acc[n]), (double)(m[i]) / 100.0);
             }
             printf("%d %s %*.2lf\n", 999, "Out of Balance", 26, (double)(-total) / 100.0);
             putchar(10);
        }
        strcpy(w[0], w[k]);
        m[0] = m[k];
    }
    return 0;
}
