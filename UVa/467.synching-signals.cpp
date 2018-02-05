#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 3601
int b[M];
int num[M];
int k;

void solve()
{
    int i, j, z, next, lim; 
    memset(b, 0, sizeof b);
     
    for(i = 0; i < k; ++i)    
        for(j = 0, next = 2 * num[i]; j < M; j += next)
             for(z = j, lim = j + num[i] - 5; z < lim && z < M; ++z)
                ++b[z];

    int mn = 0;
    for(i = 1; i < k; ++i)
       if(num[i] < num[mn])
          mn = i;
    
    for(i = num[mn] * 2; i < M; ++i)
       if(b[i] == k)
       {
           printf("synchs again at %d minute(s) and %d second(s) after all turning green.\n", i / 60, i % 60);
           return;
       }
    puts("is unable to synch after one hour.");
}

int main()
{
    char w[500];
    int cas = 1;
    while(gets(w))
    {
       char *ptr = strtok(w, " ");
       k = 0;
       while(ptr)
       {
           num[k++] = atoi(ptr);
           ptr = strtok(NULL, " ");      
       }
       printf("Set %d ", cas++);
       solve();
    }
    return 0;
}
