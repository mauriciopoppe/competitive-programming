#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define N 105
using namespace std;

bool g[N][N], color[N], mk[N];
int n, m, ans;

bool ok(int u)
{
    for(int i = 1; i <= n; i++)
    {
        if(g[u][i] && color[i]) return 0;
    }
    return 1;
}

void bt(int u, int cnt)
{
    if(u>n)
    {
        if(cnt > ans)
        {
            ans = cnt;
            for(int i = 1; i <= n; i++) mk[i] = color[i];
        }
        return;
    }
    if(cnt+n-u+1<=ans) return;
    if(ok(u))
    {
        color[u]=1;
        bt(u+1,cnt+1);
        color[u]=0;
    }
    bt(u+1,cnt);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        memset(g, 0, sizeof(g));
        memset(mk, 0, sizeof(mk));
        memset(color, 0, sizeof(color));
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            g[a][b] = g[b][a] = 1;
        }
        bt(1, 0);
        printf("%d\n", ans);
        bool flag = 1;
        for(int i = 1; i <= n; i++)
        {
            if(mk[i])
            {
                if(flag) flag = 0;
                else printf(" ");
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
