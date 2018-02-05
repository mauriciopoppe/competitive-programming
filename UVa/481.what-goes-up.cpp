#include <stdio.h>

#define N 100000
#define M 2147483647

int array[N],                //  array[i]: the ith element of input
    ptr[N],                  //  ptr[i]: pointer to the previous element in the LIS that end at array[i]
    last_p[N];               //  last_p[i]: pointer to the last element in the LIS of length i

int binary_search(int begin_p, int end_p, const int k);
void print_result(int p);

int main()
{
    int p, i = 0,
        max_len = 0;
    
    array[0] = -M, ptr[0] = 0, last_p[0] = 0;    
    
    while(scanf("%d", &array[++i]) == 1)
    {
        p = binary_search(1, max_len+1, array[i]);
        
        if(array[i] > array[last_p[p-1]])
        {
            if(p > max_len)
                ptr[i] = last_p[p-1], last_p[p] = i, max_len++;
            else
                if(array[i] <= array[last_p[p]])
                    ptr[i] = last_p[p-1], last_p[p] = i;
        }
    }
    
    printf("%d\n-\n", max_len);
    print_result(last_p[max_len]);
    
    return 0;
}
int binary_search(int begin_p, int end_p, const int k)
{
    while(begin_p < end_p)
    {
        int temp = (begin_p + end_p) / 2;
        
        if(array[last_p[temp]] < k)
            begin_p = temp + 1;
        else
            end_p = temp;
    }
    
    return begin_p;
}
void print_result(int p)
{
    if(p > 0)
    {
        print_result(ptr[p]);
        printf("%d\n", array[p]);
    }
}
