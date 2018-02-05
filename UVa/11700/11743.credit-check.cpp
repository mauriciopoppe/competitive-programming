#include<stdio.h>
#include<string.h>
int main()
{
    int cas, i;
    int t[20];
    char w[20];
    char last;
    
    scanf("%d", &cas);    
    gets(w);
    while(cas--)
    {
         gets(w);
         int size = 0;
         for(i = 0; w[i]; ++i)
            if(w[i] != ' ')
               t[size++] = w[i] - '0';
         int sum = 0;
         for(i = 0; i < size; ++i)
            if(i & 1)
                sum += t[i];
            else
            {
                if(t[i] > 4)
                  sum += 2 * t[i] - 9;
                else
                  sum += 2 * t[i];
            }
         if(sum % 10 == 0)
            puts("Valid");
         else
            puts("Invalid");
    }
    return 0;
}
