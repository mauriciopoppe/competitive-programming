#include <iostream> 
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        if(n < 0)  break;
        else if(n == 1)  cout << "0%\n";
        else  cout << ((long long)n * (long long)25) << "%\n";
    }
}
