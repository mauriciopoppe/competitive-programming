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
    string line, w;
    int cas;    
    scanf("%d", &cas);
    getline(cin, w);
    for(int z = 0; z < cas; ++z)
    {
         w = "";   
         while(getline(cin, line) && line != "END")
         {
              for(int i = 0; line[i]; ++i)
                 if(!islower(line[i]))
                    line[i] = ' ';
              w += " " + line;
         }
         map<string, bool> m;
         vector<string> check;
         stringstream ss(w);
         string buf;
         while(ss >> buf)
             m[buf] = 1, check.push_back(buf);
         int size = m.size();
         int total_words = check.size();
         map<string, int> other_m;
         
         int i = 0, j = 0, k;
         int mn = 1000000, start = -1;
         ++other_m[check[0]];
         map<string, int>::iterator it;                          
         while(1)
         {
             k = other_m.size();    
             if(k == size)
             {   
                 if(j - i + 1 < mn) 
                 {
                      mn = j - i + 1;
                      start = i + 1;
                 }
                 if(mn == size)
                    break;
                 it = other_m.find(check[i]);             
                 if(--(it->second) == 0)
                     other_m.erase(it);
                 ++i;
             }
             else
             {                 
                 if(j + 1 < total_words)              
                    ++other_m[check[++j]];
                 else break;
             }             
         }
         printf("Document %d: %d %d\n", z + 1, start, start + mn - 1);
    }
    return 0;
}
