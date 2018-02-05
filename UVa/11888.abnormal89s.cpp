#include<stdio.h>
#include<string.h>
char w[200001];

int is_pal(int i, int j)
{
    while(i < j)
       if(w[i++] != w[j--])
          return 0;
    return 1;    
}

int main()
{
    int n, i, size;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(w);
        size = strlen(w);
        for(i = 0; i < size - 1; ++i)
        {
            if(w[0] == w[i] && w[i + 1] == w[size - 1])
                if(is_pal(0, i) && is_pal(i + 1, size - 1))
                   break;
        }
        if(i == size - 1)
        {
           if(is_pal(0, size - 1))
              puts("palindrome");
           else puts("simple"); 
        }
        else
           puts("alindrome");
    }
    return 0;
}
