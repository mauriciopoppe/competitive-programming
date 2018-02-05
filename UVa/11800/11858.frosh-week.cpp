#include<stdio.h>
#define M 1000005
int v[M];
int L[M], R[M];
long long sw;

void merge(int start, int end, int mid)
{
     int i, j, size_i = 0, size_j = 0;
     int k;
     for(k = start; k <= mid; ++k)
        L[size_i++] = v[k];
     for(; k <= end; ++k)
        R[size_j++] = v[k];
     
     L[size_i] = R[size_j] = 1000000000;
     
     i = j = 0;
     for(k = start; k <= end; ++k)   
         if(L[i] > R[j])
             sw += size_i - i,
             v[k] = R[j++];
         else  
             v[k] = L[i++];
}

void merge_sort(int start, int end)
{
     if(start < end)
     {
         int mid = (start + end) / 2;
         merge_sort(start, mid);
         merge_sort(mid + 1, end);
         merge(start, end, mid);
     }
}

int main()
{
    int n, i;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 0; i < n; ++i)
           scanf("%d", &v[i]);
        sw = 0;
        merge_sort(0, n - 1);
        printf("%lld\n", sw);
    }
    return 0;
}
