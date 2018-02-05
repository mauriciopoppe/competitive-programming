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
vector<vector<string> > v(10);
bool possible[50000];
int size[10];

int main()
{
    string r = "", s;
    size[0] = 1;
    for(int i = 1; i <= 8; ++i)
    {
        r += (char)((i - 1) + '0');
        s = r;
        do{
             v[i].push_back(s);
        }while(next_permutation(s.begin(), s.end()));
        size[i] = size[i - 1] * i;
    }
    
    int n, m;
    int ct[21][3];
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        //for(int i = 0; i < size[n]; ++i)
        //   printf("%s\n", v[n][i].c_str());
           
        for(int i = 0; i < m; ++i)
           scanf("%d%d%d", &ct[i][0], &ct[i][1], &ct[i][2]);
        
        for(int i = 0; i < size[n]; ++i)
           possible[i] = 1;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < size[n]; ++j)
            {
                if(!possible[j])
                   continue;
                int a, b;

                for(int k = 0; k < n; ++k)
                   if(v[n][j][k] - '0' == ct[i][0])
                   {
                      a = k;
                      break;
                   }
                   
                for(int k = 0; k < n; ++k)
                   if(v[n][j][k] - '0' == ct[i][1])
                   {
                      b = k;
                      break;
                   }                
                //printf("%d %d\n", a, b);
                //SP;
                if(ct[i][2] > 0)
                {
                    if(abs(a - b) > ct[i][2])
                       possible[j] = 0;         
                }
                else 
                {
                    if(abs(a - b) < -ct[i][2]) 
                       possible[j] = 0;
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < size[n]; ++i)
           cnt += possible[i];
        printf("%d\n", cnt);
    }       
    return 0;
}
