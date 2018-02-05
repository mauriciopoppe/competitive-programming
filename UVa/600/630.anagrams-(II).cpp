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

char sorted[1001][22];
char words[1001][22];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas, n;
    char w[50], word_k[50];
    scanf("%d", &cas);
    gets(w);
    F(z, cas)
    {
        if(z)NL; 
        gets(w);
        scanf("%d", &n);
        gets(w);
        F(i, n)
        {
            gets(words[i]);
            strcpy(sorted[i], words[i]);
            sort(sorted[i], sorted[i] + strlen(sorted[i]));           
        }
        while(gets(w) && strcmp(w, "END"))
        {
            strcpy(word_k, w);
            sort(w, w + strlen(w));            
            vector<int> v;
            F(i, n)
                if(!strcmp(w, sorted[i]))
                   v.push_back(i);
            printf("Anagrams for: %s\n", word_k);
            if(v.size())
            {
                int size = v.size();
                for(int i = 0; i < size; ++i)
                   printf("%3d) %s\n", i + 1, words[v[i]]);
            }
            else
                printf("No anagrams for: %s\n", word_k);
        }
    }
    return 0;
}
