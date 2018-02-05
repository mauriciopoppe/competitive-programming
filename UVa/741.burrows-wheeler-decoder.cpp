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
    string w;
    int n;
    int cas = 0;
    while(cin>>w>>n && n)
    {
        if(cas)NL;
        cas = 1;            
        int size = w.size();            
        vector<string> str(size);
        F(i,size) 
           str[i] = string(w.begin() + i, w.begin() + i + 1);
        sort(str.begin(), str.end());
        /*F(i,size)
           cout << str[i] << endl;*/
        F(i,size - 1)
        {
            F(j,size)
               str[j] = w[j] + str[j];
            sort(str.begin(), str.end());
            /*F(j,size)
               cout << str[j] << endl;
            SP;*/
        }
        printf("%s\n",str[n - 1].c_str());
    }
    return 0;
}
