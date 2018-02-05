#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main()
{
    string a;
    while(cin>>a && a!="#")
    {
         if(next_permutation(a.begin(),a.end()))cout<<a;
         else cout<<"No Successor";
         printf("\n");             
    }
    return 0;
}
