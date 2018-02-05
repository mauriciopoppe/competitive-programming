#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        stringstream ss(s);
        string buf;
        int i=0;
        while(ss>>buf)
        {
             if(i)printf(" ");         
             else i=1;
             reverse(buf.begin(),buf.end());
             cout<<buf;         
        }                  
        printf("\n");
    }
    return 0;
}
