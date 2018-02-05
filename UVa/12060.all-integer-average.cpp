#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int gcd(int a, int b)
{
    if(b == 0)return a;
    return gcd(b, a % b);    
}

int main()
{

    int k, n;
    char hyphen[11];
    char line[1000000];
    memset(hyphen, '-', sizeof hyphen);
    hyphen[10] = '\0';
    int cas = 1;    
    while(scanf("%d", &n) && n)
    {
        gets(line);
        int sum = 0;
        char *ptr = strtok(line, " ");
        while(ptr)
           sum += atoi(ptr), ptr = strtok(NULL, " ");
         
        printf("Case %d:\n", cas++);
        if(abs(sum) % n == 0)
        {
            printf("%s%d\n", sum < 0 ? "- " : "", abs(sum) / n);
            continue;    
        }        
        if(abs(sum) < n)
        {
            int b = sum < 0;
            sum = abs(sum);
            k = gcd(sum, n);
            int mx = max((int) log10(sum / k), (int) log10(n / k)) + 1;
            printf("%s%*d\n%s%s\n%s%*d\n", b ? "  " : "", mx, sum / k
                                         , b ? "- " : "", hyphen + 10 - mx
                                         , b ? "  " : "", mx, n / k);
        }
        else
        {
            int big = abs(sum) / n;
            int b = sum < 0;
            sum = abs(sum) - big * n;
            k = gcd(sum, n);
            int mx = max((int) log10(sum / k), (int) log10(n / k)) + (int)log10(big) + 2;
            printf("%s%*d\n%s%d%s\n%s%*d\n", b ? "  " : "", mx, sum / k
                                         , b ? "- " : "", big, hyphen + 10 - mx + (int)log10(big) + 1
                                         , b ? "  " : "", mx, n / k);
        }
    }
    return 0;
}
