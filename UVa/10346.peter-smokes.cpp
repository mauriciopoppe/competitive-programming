#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    long long r;
    int t;
    char s[15]={0};
    while(t--)
    {
       scanf("%lld",&r);    
       r*=567;
       r/=9;
       r+=7492;
       r*=235;
       r/=47;
       r-=498;
       s=ltoa(r);   
    }
}
