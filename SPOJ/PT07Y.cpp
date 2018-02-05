/*
 * solitaire.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: Mauricio Poppe -- maurizzzio@maurizzzio.com
 */
#include<stdio.h>
#include<stdlib.h>
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
using namespace std;

vector<vector<int> > g;
int n, roads;
int solved;
int discovered[10001];

void dfs(int node){
    if(!solved) return;
    discovered[node] = 1;
    TR(g[node], it){
        if(!discovered[*it])
            dfs(*it);
        else if(discovered[*it] && node != *it)
                solved = 0;
    }
}

int main(){
    int x, y;
    while(scanf("%d%d", &n, &roads) != EOF){
        g.clear();
        g.resize(n);
        for(int i = 0; i < roads; ++i){
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        solved = 1;
        dfs(0);
        if(solved) puts("YES");
        else puts("NO");
    }
    return 0;
}