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
#define M 1001
bool can_type[11];
int size[M];
char w[M][55];
bool good[M];
map<char, int> letter;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    letter['q'] = letter['z'] = letter['a'] = 1;
    letter['w'] = letter['s'] = letter['x'] = 2;
    letter['e'] = letter['d'] = letter['c'] = 3;
    letter['r'] = letter['f'] = letter['v'] = letter['t'] = letter['g'] = letter['b'] = 4;
    letter[' '] = 5;
    letter['y'] = letter['h'] = letter['n'] = letter['u'] = letter['j'] = letter['m'] = 7;
    letter['i'] = letter['k'] = letter[','] = 8;
    letter['o'] = letter['l'] = letter['.'] = 9;
    letter['p'] = letter[';'] = letter['/'] = 10;
    
    int fingers, words, k;
    while(scanf("%d%d", &fingers, &words) != EOF)
    {
         fill(can_type, can_type + 11, 1);               
         F(i, fingers)               
            scanf("%d", &k), can_type[k] = 0;
         can_type[5] = can_type[5] | can_type[6];
         
         getchar();
         fill(good, good + words, 0);
         int mx = -1;
         F(i, words)
         {
             scanf("%s",w[i]);
             size[i] = strlen(w[i]);
             int j;
             for (j = 0; j < size[i]; ++j)
                 if(!can_type[letter[w[i][j]]])
                    break; 
             if(j == size[i])
                good[i] = 1, mx = max(mx, size[i]);
         }
         
         vector<string> words_sorted;
         F(i, words)
             if(good[i] && size[i] == mx)
                words_sorted.push_back(string(w[i], w[i] + size[i])); 
         sort(words_sorted.begin(), words_sorted.end());
         vector<string>::iterator it = unique(words_sorted.begin(), words_sorted.end());
         words_sorted.resize(it - words_sorted.begin());
         k = words_sorted.size();
         printf("%d\n",k);
         F(i, k)
            printf("%s\n",words_sorted[i].c_str());
    }
    return 0;
}
