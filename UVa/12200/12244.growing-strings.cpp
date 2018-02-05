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
#define MAXN 1010005
//#define DEBUG
typedef long long LL;

struct word{
       char w[1002];
       int size;
       bool operator<(const word &other) const
       {
           //if(size != other.size)
               return size < other.size;
           //return strcmp(w,other.w);
       }     
} str[10001];

int belong[MAXN];

int n,t;  //n es el tamaño de la cadena
int p[MAXN],r[MAXN],h[MAXN];
//p es el inverso del suffix array, no usa indices del suffix array ordenado
//h el el tamaño del lcp entre el i-esimo y el i+1-esimo elemento de suffix array ordenado
char s[MAXN];

void fix_index(int *b, int *e) {
   int pkm1, pk, np, i, d, m;
   pkm1 = p[*b + t];
   m = e - b; d = 0;
   np = b - r;
   for(i = 0; i < m; i++) {
      if (((pk = p[*b+t]) != pkm1) && !(np <= pkm1 && pk < np+m)) {
         pkm1 = pk;
         d = i;
      }
      p[*(b++)] = np + d;
   }
}

bool comp(int i, int j) {
   return p[i + t] < p[j + t];
}
void suff_arr() {
   int i, j, bc[256];
   t = 1;
   for(i = 0; i < 256; i++) bc[i] = 0; 
   for(i = 0; i < n; i++) ++bc[int(s[i])];
   for(i = 1; i < 256; i++) bc[i] += bc[i - 1];
   for(i = 0; i < n; i++) r[--bc[int(s[i])]] = i;
   for(i = n - 1; i >= 0; i--) p[i] = bc[int(s[i])];
   for(t = 1; t < n; t *= 2) {
      for(i = 0, j = 1; i < n; i = j++) {
         while(j < n && p[r[j]] == p[r[i]]) ++j;
         if (j - i > 1) {
            sort(r + i, r + j, comp);
            fix_index(r + i, r + j);
         }
      }
   }
}

void lcp() {
   int tam = 0, i, j;
   for(i = 0; i < n; i++)if (p[i] > 0) {
      j = r[p[i] - 1];
      while(s[i + tam] == s[j + tam]) ++tam;
      h[p[i] - 1] = tam;
      if (tam > 0) --tam;
   }
   h[n - 1] = 0;
}

int bin_search(char *q, int &size)
{
    int i,j;
    i = 0;
    j = n;
    while(i <= j)
    {
         int mid = (i+j)>>1;
         //string a = string(s+r[mid],s+r[mid]+size);
        // string b = string(q,q+size);
         //printf("[%s]\n",a.c_str());
        // printf("[%s]\n",b.c_str());
         int cmp = strncmp(s + r[mid], q, size);
         //printf("%d\n",cmp);
         if(cmp == 0)
            return mid;
         if(cmp < 0) 
            i = mid + 1;
         else
            j = mid - 1;
         //SP;
    }
    return -1;
}

int main()
{
    //freopen("big.txt","r",stdin);
    //freopen("growing.in","r",stdin);
    //freopen("out.txt","w",stdout);
    long start = clock();
    int n_words;
    int i,j,k;
    int check;
    while(scanf("%d",&n_words) && n_words)
    {                       
        gets(str[0].w);
        n = -1;
        for(i = 0; i < n_words; ++i)
        {  
           gets(str[i].w);
           str[i].size = strlen(str[i].w);
        }
        
        //now topological sort the words
        sort(str, str + n_words);
        
        //build main word
        for(i = 0; i < n_words; ++i)
        {
           for(j = 0; j < str[i].size; ++j)
           {
              s[++n] = str[i].w[j];
              belong[n] = i;
           }
           s[++n] = '#' + i%4;
        }
        ++n;
        /*NL;
        F(z,n_words)
           printf("%s\n",str[z].w);*/
        
        int dp[n_words];
        memset(dp, 0, sizeof dp);
                
        //suffix array and lcp
        suff_arr();
        lcp();
        
        /*F(z,n)
        {
            printf("[%d] %d %s\n",z,r[z],s+r[z]);
        }
        system("pause");*/
        //for each word find its ocurrence in other words and save it as an edge
        for(i = 0; i < n_words; ++i)
        {
            int find_mid = bin_search(str[i].w, str[i].size);
            //mark this location in the graph            
            set<int> path;            
            path.insert(belong[r[find_mid]]);
            //check backwards
            check = find_mid - 1;
            while(check >= 0 && h[check] >= str[i].size)
            {
               path.insert(belong[r[check]]);         
               --check;
            }
            //check forward
            check = find_mid;
            while(check < n && h[check] >= str[i].size)
            {
               path.insert(belong[r[check + 1]]);         
               ++check;
            }
            path.erase(i);
            k = dp[i] + 1;
            TR(path,it)
            {
               //printf("%d ",*it);        
               dp[*it] = max(dp[*it], k);
            }
            /*NL;
            F(z,n_words)
               printf("%d ",dp[z]);
            NL;*/
        }

        int mx = 0;
        for(i = 0; i < n_words; ++i)
           mx = max(dp[i],mx);
        printf("%d\n",mx+1);
    }
    //printf("%ld\n",clock()-start);
    return 0;
}
