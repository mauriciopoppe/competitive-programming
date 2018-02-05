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
    map<string, int> m;
    vector<string> v;
    vector<vector<string> > words(1);
    string w;  
    int k = 1;
    int temp;  
    while(cin >> w && w[0] != 'X')
    {
        string t = w;
        sort(ALL(t));
        //cout << t << endl;
        if(temp = m[t])
           words[temp].push_back(w);
        else
        {
           m[t] = k;
           words.push_back(v);
           words[k++].push_back(w);
        }
    }
    
    for(int i = 1; i < k; ++i)
       sort(ALL(words[i]));
    
    while(cin >> w && w[0] != 'X')
    {
        string t = w;
        sort(ALL(t));
        //cout << t << endl;
        if(m[t])
           TR(words[m[t]], it)
              printf("%s\n", it->c_str());
        else
           puts("NOT A VALID WORD");
        puts("******");
    }
    return 0;
}
