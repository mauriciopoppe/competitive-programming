#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<list>
using namespace std;

int main()
{
    int n,x,a;
    while(cin>>n && n)
    {
         list<int> l;        
         int t=0;
         for(int j=0;j<n;j++)
         {        
             cin>>x;
             for(int i=0;i<x;i++)
             {
                 cin>>a;
                 l.push_back(a);    
             }
             l.sort();
             t+=(l.back()-l.front());            
             l.pop_front();
             l.pop_back();            
         }             
         cout<<t<<endl;
    }
    return 0;
}
