#include<stdio.h>
#include<math.h>
int n;
int v[50], s = 0;
int sol[10000][50];
int size[10000];
void bt(int n, int k)
{
     int temp;
     int i;
     if(k > 0)
        i = v[k - 1];
     else
        i = 2;
     for(; i < (int)sqrt(n) + 1; ++i)     
        if(n % i == 0) 
        {
            temp = v[k];
            v[k] = i;
            bt(n / i, k + 1);
            v[k] = temp; 
        }
     if(n > 1 && k)
     {
        v[k] = n;
        for(i = 0; i <= k; ++i)
           sol[s][i] = v[i];
        size[s++] = k;
     }
}

int main()
{
    int i, j;
    while(scanf("%d", &n) && n)
    {
        s = 0;
        bt(n, 0);
        printf("%d\n", s);
        for(i = 0; i < s; ++i)
        {
            for(j = 0; j <= size[i]; ++j)
            {
               if(j)putchar(' ');
               printf("%d", sol[i][j]); 
            }
            putchar(10);  
        }
    }
    return 0;
}
