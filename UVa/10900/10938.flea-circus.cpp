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
#define sci(d) scanf("%d", &d)
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
using namespace std;
#define M 5010
int ancestor[M][15];
int level[M];
vector<vector<int> > graph;
int logL;

void find_level(int node, int parent, int lvl){
    level[node] = lvl;
    ancestor[node][0] = parent;
    TR(graph[node], it)
        if(*it != parent)
            find_level(*it, node, lvl + 1);
}

void preprocess_ancestors(int n){
    for(int j = 1; (1 << j) <= n; ++j)
        for(int i = 1; i <= n; ++i)
            if(ancestor[i][j - 1] != -1)
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
}

int lowest_common_ancestor(int x, int y){

    if(level[x] < level[y])
        swap(x, y);

    for(logL = 1; (1 << logL) <= level[x]; ++logL);
    --logL;

    for(int i = logL; i >= 0; --i)
        if(level[x] - (1 << i) >= level[y])
            x = ancestor[x][i];

    if(x == y) return x;
    for(int i = logL; i >= 0; --i)
        if(ancestor[x][i] != -1 && ancestor[x][i] != ancestor[y][i]){
            x = ancestor[x][i];
            y = ancestor[y][i];
        }
    return ancestor[x][0];
}

int find_kth_ancestor(int x, int k){
    for(int i = 1; i <= k; i <<= 1)
        if(i & k)
            x = ancestor[x][i / 2];
    return x;
}

int main(){
    int n, q, x, y, u, v, r1, r2;
    while(scanf("%d", &n) && n){

        // init
        memset(ancestor, -1, sizeof ancestor);

        graph.clear();
        graph.resize(n + 10);
        F(i, n - 1){
            scanf("%d%d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        // find all the levels of each node in the tree
        find_level(1, -1, 0);

        // build lca
        preprocess_ancestors(n);

        scanf("%d", &q);
        F(i, q){
            scanf("%d%d", &u, &v);
            int l = lowest_common_ancestor(u, v);

            if (l == -1) l = 1;
            int d = level[u] + level[v] - 2 * level[l];
            if (d % 2 == 0) {
                x = d >> 1;
                if (level[u] < level[v]) swap(u, v);
                for (int j = logL;j >=0 ;j--)
                    if ( ancestor[u][j] != -1 && x - (1<<j) >= 0) {
                        u = ancestor[u][j];
                        x-=(1<<j);
                    }
                printf("The fleas meet at %d.\n", u);
            }
            else {
                x = d >> 1;
                if ( level[u] < level[v]) swap(u, v);
                for (int j=logL;j>=0;j--)
                    if ( ancestor[u][j] != -1 && x - (1<<j) >=0 ) {
                        u = ancestor[u][j];
                        x-=(1<<j);
                    }
                r2 = u;
                r1 = ancestor[u][0];
                printf("The fleas jump forever between %d and %d.\n", min(r1, r2), max(r1, r2));
            }
        }
    }
    return 0;
}
