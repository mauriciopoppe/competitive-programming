/*
 * 4477.cpp
 *
 *  Created on: Jul 27, 2011
 *      Author: Mauricio
 */

#include<stdio.h>
#include<string.h>
#include<set>
#include<iostream>
#include<algorithm>
#define for_each_it(container, it)  \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)
using namespace std;

#define MAXN 100005			//max size of the word + '$' characters

typedef long long LL;

int n;						//size of the big string
int t;  					//shift 2 helper
int p[MAXN];				//inverse of the suffix array
int r[MAXN];				//suffix array
int h[MAXN];				//longest common prefix between suffix[i] and suffix[i+1]
char s[MAXN];				//the BIG BIG word

//suffix array methods
void fix_index(int *b, int *e)
{
   int pkm1, pk, np, i, d, m;
   pkm1 = p[*b + t];
   m = e - b; d = 0;
   np = b - r;
   for(i = 0; i < m; ++i)
   {
      if (((pk = p[*b+t]) != pkm1) && !(np <= pkm1 && pk < np+m))
      {
         pkm1 = pk;
         d = i;
      }
      p[*(b++)] = np + d;
   }
}

bool comp(int i, int j)
{
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

//longest common prefix
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


int main()
{
    int i;
    while(gets(s) && s[0] != '*')
    {
    	n = strlen(s);
    	s[n++] = '$';
        //suffix array and lcp
        suff_arr();
        lcp();
        int total = h[0]==0? 0 : h[0];

        //for each word find its occurrence in other words and save it as an edge
        for(i = 1; i < n; ++i)
        {
        	if(h[i] > h[i - 1])
        		total += h[i] - h[i - 1];
        }
        printf("%d\n",total);
    }
    return 0;
}
