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
#define X first
#define Y second
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
using namespace std;
#define M 120
typedef pair<int, int> pii;

struct node{
    pii point;
    double w;
    bool operator<(const node &other) const{
        return w > other.w;
    }
};

char graph[M][M];
double dist[M][M];
int disc[M][M];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};
int row, col;
pii start, end;

int check(int x, int y){
    return x >= 0 && x < row && y >= 0 && y < col;
}

double bfs(double d_v){
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            dist[i][j] = 1e20, disc[i][j] = 0;;

    node start_node = {start, 0.0};
    priority_queue<node> q;
    q.push(start_node);
    dist[start.X][start.Y] = 0;

    while(!q.empty()){
        node top = q.top();
        q.pop();

        if(disc[top.point.X][top.point.Y]) continue;
        disc[top.point.X][top.point.Y] = 1;
        for(int i = 0; i < 4; ++i){
            int nx = top.point.X + dx[i], ny = top.point.Y + dy[i];
            double td = i % 2 != 0 ? d_v : 1.0;
            if(check(nx, ny) && graph[nx][ny] == ' ' &&
               dist[nx][ny] > dist[top.point.X][top.point.Y] + td){
                   dist[nx][ny] = dist[top.point.X][top.point.Y] + td;
                   node to_push = {pii(nx, ny), dist[nx][ny]};
                   q.push(to_push);
            }
        }
    }
    return dist[end.X][end.Y];
}

int main(){
    int cas;
    double desired;
    scanf("%d", &cas);
    F(z, cas){
        scanf("%lf%d", &desired, &row);
        gets(graph[0]);
        for(int i = 0; i < row; ++i){
            gets(graph[i]);
            if(!i) col = strlen(graph[i]);
            for(int j = 0; j < col; ++j){
                if(graph[i][j] == 'S') start.X = i, start.Y = j, graph[i][j] = ' ';
                if(graph[i][j] == 'E') end.X = i, end.Y = j, graph[i][j] = ' ';
            }
        }

        double l = 0.0, r = 1e4, mid, bfs_test;
        while(fabs(r - l) > 1e-8){
            mid = (l + r) * 0.5;
            bfs_test = bfs(mid);
            //printf("%lf %lf\n", mid, bfs_test);
            if(bfs_test > desired) r = mid;
            else l = mid;
        }
        printf("Case #%d: %.3lf%c", z + 1, l * 100.0, '%');
    }
    return 0;
}
