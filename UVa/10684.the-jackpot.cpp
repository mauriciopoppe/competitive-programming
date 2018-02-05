#include <iostream>          //  Accepted
#define N 10000
using namespace std;
int main()
{
    int n, array[N+1], max_value;
    while((cin >> n) && n)
    {
        array[0] = max_value = 0; 
        for(int i = 1; i <= n; i++)
        {
            cin >> array[i];
            //array[i] >?= array[i-1] + array[i];
            array[i] = array[i]>array[i-1]+array[i]?array[i]:array[i-1]+array[i];
            //max_value >?= array[i];
            max_value = max_value>array[i]?max_value:array[i];
            for(int j=0;j<=n;j++)
                printf("%d ",array[j]);
            printf("\n");       
        }     
        if(max_value > 0)
            cout << "The maximum winning streak is " << max_value << ".\n";
        else
            cout << "Losing streak.\n";
    }    
    return 0;
}
