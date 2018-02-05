/*
 * 1227.cpp
 *
 *  Created on: Mar 31, 2012
 *      Author: mauricio
 */

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
#define MAXN 10000050
int best;
int n_str;
char str[MAXN];                    //the initial string, NOTE: concatenate it with '$'
char word[MAXN];
int s[MAXN], SA[MAXN];            //<s> char to int representation, <SA> Suffix Array
int SA_inverse[MAXN];                //<SA_inverse> is the inverse of <SA>
int lcp[MAXN];                    //<lcp> longest common prefix
int word_number[MAXN];			  //word number aka belong to
int size;                        //size of the string <str>

// lexicographic order for pairs
inline bool leq(int a1, int a2, int b1, int b2) {
    return(a1 < b1 || (a1 == b1 && a2 <= b2));
}

// and triples
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3)));
} // and triples

// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(int* a, int* b, int* r, int n, int K) {// count occurrences
    int* c = new int[K + 1]; // counter array
    for (int i = 0; i <= K; i++) c[i] = 0; // reset counters
    for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
    for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (int i = 0;  i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
    delete [] c;
}

// find the suffix array SA of s[0..n-1] in {1..K}ˆn
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(int* s, int* SA, int n, int K) {
    int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
    int* s12 = new int[n02+3]; s12[n02] = s12[n02+1] = s12[n02+2] = 0;
    int* SA12 = new int[n02+3]; SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
    int* s0 = new int[n0];
    int* SA0 = new int[n0];
    // generate positions of mod 1 and mod 2 suffixes
    // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (int i=0, j=0; i < n + (n0-n1); i++)
        if (i%3 != 0) s12[j++] = i;
    // lsb radix sort the mod 1 and mod 2 triples
    radixPass(s12 , SA12, s+2, n02, K);
    radixPass(SA12, s12 , s+1, n02, K);
    radixPass(s12 , SA12, s  , n02, K);
    // find lexicographic names of triples
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++) {
        if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
            name++;
            c0 = s[SA12[i]];
            c1 = s[SA12[i]+1];
            c2 = s[SA12[i]+2];
        }
        if (SA12[i]%3 == 1) s12[SA12[i]/3] = name; // left half
        else s12[SA12[i]/3 + n0] = name; // right half
    }
    // recurse if names are not yet unique
    if (name < n02) {
        suffixArray(s12, SA12, n02, name);
        // store unique names in s12 using the suffix array
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    } else // generate the suffix array of s12 directly
        for (int i = 0;  i < n02; i++) SA12[s12[i] - 1] = i;
    // stably sort the mod 0 suffixes from SA12 by their first character
    for (int i = 0, j = 0; i < n02; i++)
        if (SA12[i] < n0) s0[j++] = 3*SA12[i];
    radixPass(s0, SA0, s, n0, K);
    // merge sorted SA0 suffixes and sorted SA12 suffixes
    for (int p = 0, t = n0-n1, k = 0; k < n; k++) {
        #define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
        int i = GetI(); // pos of current offset 12 suffix
        int j = SA0[p]; // pos of current offset 0 suffix
        if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
            leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
            leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
        {// suffix from SA12 is smaller
            SA[k] = i; t++;
            if (t == n02) // done --- only SA0 suffixes left
            for (k++; p < n0; p++, k++) SA[k] = SA0[p];
        } else {// suffix from SA0 is smaller
            SA[k] = j; p++;
            if (p == n0) // done --- only SA12 suffixes left
            for (k++; t < n02; t++, k++) SA[k] = GetI();
        }
    }
    delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
}

void build_lcp()
{
    int tam = 0;        //initially no common characters
    int i, j;           //loop

    //create the ranks
    for(i = 0; i < size; ++i)
        SA_inverse[SA[i]] = i;

    for(i = 0; i < size; i++)
        if (SA_inverse[i] > 0)    //check only for the suffixes that have a predecessor
        {
            //get the previous suffix from the SA
            j = SA[SA_inverse[i] - 1];

            //check starting from the character at position tam in the string
            while(str[i + tam] == str[j + tam])
                ++tam;

            //LCP is the common characters from suffix[j] and suffix[i]
            lcp[SA_inverse[i] - 1] = tam;

            //we know that the next suffix must share at least tam - 1 characters
            //only if tam is bigger than zero
            if (tam > 0)
                --tam;
        }
    //size of the last suffix is zero
    lcp[size - 1] = 0;
}
bool bsearch(int length_to_find)
{
    int i, j;
    int cnt;
    bool check[10];
    for(i = 1; i < size; i = j + 1)
    {
        while(i < size && lcp[i] < length_to_find)
           ++i;
        if(i == size)
           break;
        cnt = 0;
        memset(check, 0, sizeof check);
        for(j = i; lcp[j] >= length_to_find; ++j)
           if(!check[word_number[SA[j]]])
           {
                check[word_number[SA[j]]] = 1;
                ++cnt;
           }
        if(!check[word_number[SA[j]]])
           ++cnt;
        //printf("%d %d\n", cnt, j);
        if(cnt == n_str)
           return 1;
    }
    return 0;
}

int main()
{
    int cas;
    int mn, j;
    scanf("%d", &cas);
    while(cas--)
    {
         scanf("%d", &n_str);
         gets(word);
         mn = MAXN;
         size = 0;
         int k = 'T';
         for(int i = 0; i < n_str; ++i)
         {
              gets(word);
              for(j = 0; word[j]; ++j)
                  s[size] = str[size] = word[j],
                  word_number[size++] = i + 1;
              s[size] = str[size] = (char) (i + '$');
              ++size;
              mn = min(j, mn);
         }

         suffixArray(s, SA, size, k);
         build_lcp();

         int low = 1, up = mn + 1, mid, best = -1;
         while(low <= up)
         {
             mid = (low + up) >> 1;
             if(bsearch(mid))
                low = mid + 1, best = mid;
             else
                up = mid - 1;
         }
         printf("%d\n", best);
    }
    return 0;
}
