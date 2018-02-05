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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s,w;
    vector<string> word;    
    int c = 0;
    while(getline(cin,s) && s[0] != '0')
    {
         int size = s.size();
         for(int i = 0; i < size;)
         {
             if(isalpha(s[i]))
             {
                 string t="";
                 while(isalpha(s[i]))
                    t+=s[i++];
                 
                 word.push_back(t);
                 printf("%s",t.c_str());
             }
             else if(isdigit(s[i]))
             {
                 int t = 0;             
                 while(isdigit(s[i]))
                    t = t*10 + s[i++]-'0'; 
                 
                 int ws = word.size();
                 word.push_back(word[ws - t]);                 
                 word.erase(word.begin() + ws - t);
                 printf("%s",word[ws - 1].c_str());
             }
             //printf("[%c]",s[i]);
             if(i < size)
                putchar(s[i++]);
         }
         NL;
    }
    return 0;
}
