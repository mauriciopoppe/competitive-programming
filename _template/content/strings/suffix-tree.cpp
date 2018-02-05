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

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

#define MAXN 200100
#define MAXC 27
#define E(s,c) edge[s][((c)=='#'?0:((c)-'a'+1))]

/*** Suffix Tree (Ukkonen 95) ***/
struct Edge { int a,b,c; };
int slink[MAXN], nsi, root, tlen;
Edge edge[MAXN][MAXC];
char text[MAXN];

void canonize(int &s, int &a, int b){
	if (s==0) s = root, a++;
	while (a <= b){
		Edge e = E(s,text[a]);
		if (e.b - e.a > b - a) break;
		a += e.b - e.a + 1;
		s = e.c;
	}
}

void update(int &s, int &a, int b){
	int oldr = root, ns;
	while (true){
		if (a>=b){
			if (E(s,text[b]).a!=-1) break; else ns = s;
		} else {
			Edge e = E(s,text[a]);
			if (text[b] == text[e.a + b-a]) break; else ns = ++nsi;
			E(s,text[e.a]) = (Edge){ e.a, e.a + b-a - 1, ns };
			E(ns,text[e.a+b-a]) = (Edge){ e.a + b-a, e.b, e.c };
		}
		E(ns,text[b]) = (Edge) { b, tlen-1, ++nsi };
		if (oldr != root) slink[oldr] = ns;
		oldr = ns;
		s = slink[s];
		canonize(s, a, b-1);
	}
	if (oldr != root) slink[oldr] = s;
}

void suffix_tree(){
	memset(edge,-1,sizeof(edge));
	int bottom = nsi = 0;
	slink[root = ++nsi] = bottom;
	for (int s=root,a=0,b=0; b<tlen; b++){
		update(s,a,b);
		canonize(s,a,b);
	}
}
/*** end of Suffix Tree ***/

int main()
{
	gets(text);
	return 0;
}
