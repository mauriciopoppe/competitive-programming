#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

bool vowel(char c)
{
     return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
int check(string &s, int n)
{
    int size = s.size();
    int c = 0;
    int f = 0;
    for(int i = 0; i < size; ++i)
    {
        if(vowel(s[i]))
            f = 1; 
        else
        {
            if(f)
              c++;
            f = 0; 
        }
    }
    if(f) c++;
    return c == n;
}
int main()
{
    string s[3];
    while(1)
    {
        getline(cin, s[0], '/');
        getline(cin, s[1], '/');
        getline(cin, s[2], '\n');
        //printf("%s %s %s\n",s[0].c_str(),s[1].c_str(),s[2].c_str());
        if(s[0] == "e" && s[1] == "o" && s[2] == "i")
           break;
        if(!check(s[0], 5))    
        {
           printf("1\n");
           continue;                        
        }
        if(!check(s[1], 7))    
        {
           printf("2\n");
           continue;                        
        }
        if(!check(s[2], 5))    
        {
           printf("3\n");
           continue;                        
        }
        printf("Y\n");
    }       
    return 0;
}
