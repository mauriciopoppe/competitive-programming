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
int graph[100][100];
int dis[100];
int is_a_node[100];
int c;
char w[500];

void dfs(int k)
{
    dis[k] = 1;
    ++c;
    for(int i = 'A'; i <= 'Z'; ++i)
        if(graph[k][i] && !dis[i])
           dfs(i);
}

int main()
{
    int cas;
    char from, to;
    scanf("%d", &cas);
    gets(w);
    while(cas--)
    {
        memset(graph, 0, sizeof graph);
        memset(dis, 0, sizeof dis);
        memset(is_a_node, 0, sizeof is_a_node);
        while(gets(w) && w[0] != '*')
        {
            sscanf(w, "(%c,%c)", &from, &to);
            graph[from][to] = graph[to][from] = 1;
        }
        gets(w);
        char *ptr = strtok(w, ",");
        while(ptr)
        {
             is_a_node[ptr[0]] = 1;
             ptr = strtok(NULL, ",");     
        }
        int tree = 0, acorn = 0;
        for(int i = 'A'; i <= 'Z'; ++i)
        {
            if(is_a_node[i] && !dis[i])
            {
                c = 0;
                dfs(i);
                if(c > 1)
                   ++tree;
                else
                   ++acorn;   
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
    return 0;
}
