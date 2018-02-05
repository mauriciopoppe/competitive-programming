#include<stdio.h>
#define M 60
int grid[M][M];
int value[M][M];
int cost[M][M];
int row, col, wall_cost, bumpers;

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int check(int x, int y)
{
    return x > 0 && x < row - 1 && y > 0 && y < col - 1;
}

int solve(int x, int y, int dir, int life)
{
    int i = 3 - dir;
    int val = 0;
    
    while(life > 1)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if(check(nx, ny))
        {
            if(grid[nx][ny])
            {
                val += value[nx][ny];
                life -= cost[nx][ny];
                ++i;
                if(i == 4) i = 0;
            }
            else 
                x = nx, y = ny;
        }
        else
        {
            life -= wall_cost;
            ++i;
            if(i == 4) i = 0;
        }
        --life;
    }
    printf("%d\n", val);
    return val;
}

int main()
{    
     int dir, life;
     scanf("%d%d", &row, &col);
     scanf("%d%d", &wall_cost, &bumpers);
     int x, y, v, c, i;
     for(i = 0; i < bumpers; ++i)
     {
         scanf("%d%d%d%d", &x, &y, &v, &c);
         --x, --y;
         grid[x][y] = 1;
         value[x][y] = v;
         cost[x][y] = c;
     }
     c = 0;     
     while(scanf("%d%d%d%d", &x, &y, &dir, &life) != EOF)
         c += solve(x - 1, y - 1, dir, life);
     printf("%d\n", c);
     return 0;
}
