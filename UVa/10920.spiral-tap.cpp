#include<stdio.h>
#include<math.h>
int main()
{
    int size, n, row, col;
    while(scanf("%d%d", &size, &n) && size && n)
    {
        int k = (int)sqrt(n);
        if(k & 1)
        {
            if(sqrt(n) == (double)k)
            {
                row = (size + 1) / 2 + k / 2;
                col = (size + 1) / 2 + k / 2;
            }
            else
            {
                int low = k + 1;
                if(n <= k * k + low)
                {
                    row = (size + 1) / 2 + k / 2 + 1;
                    col = (size + 1) / 2 + k / 2 - (n - (k * k + 1)); 
                }
                else
                {
                    col = (size + 1) / 2 - k / 2 - 1;
                    row = (size + 1) / 2 + (k / 2) - (n - (k * k + low + 1));
                }
            }
        }
        else
        {
            if(sqrt(n) == (double)k)
            {                      
                row = (size + 1) / 2 - k / 2 + 1;
                col = (size + 1) / 2 - k / 2;
            }
            else
            {
                int low = k + 1;
                if(n <= k * k + low)
                {
                    row = (size + 1) / 2 - k / 2;
                    col = (size + 1) / 2 - k / 2 + (n - (k * k + 1)); 
                }
                else
                {
                    col = (size + 1) / 2 + k / 2;
                    row = (size + 1) / 2 - k / 2 + 1 + (n - (k * k + low + 1));
                }
            }
        }
        printf("Line = %d, column = %d.\n", row, col);
    }
    return 0;
}
