#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
struct player{
       int x, y;
       int v;
} p[21], ball;

int dist(struct player p1, struct player p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int main()
{
    char w[500];
    int n_players, n_balls;
    int a, b, c, d, e ,f, g;
    int i, j;
    int t;
    char C;
    int n = 0;
    while((C = getchar()) && isalpha(C));
    while((C = getchar()) && isdigit(C))
       w[n++] = C;
    w[n] = '\0';
    n_players = atoi(w);
    for(i = 0; i < n_players; ++i)
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].v);
    getchar();
    n = 0;
    while((C = getchar()) && isalpha(C));
    while((C = getchar()) && isdigit(C))
       w[n++] = C;
    w[n] = '\0';
    n_balls = atoi(w);
    for(i = 0; i < n_balls; ++i)
    {
        scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
        for(j = 1; ;++j)
           if(a * j * j + b * j + c <= 0)
               break;
        t = j;        
        ball.x = d * t + e;
        ball.y = f * t + g;
        if(ball.x < 0 || ball.y < 0)
        {
            printf("Ball %d was foul at (%d,%d)\n", i + 1, ball.x, ball.y);
            continue; 
        }
        
        for(j = 0; j < n_players; ++j)
            if((p[j].v * t) * (p[j].v * t) >= dist(p[j], ball))
               break;
               
        if(j == n_players)
            printf("Ball %d was safe at (%d,%d)\n", i + 1, ball.x, ball.y);
        else
            printf("Ball %d was caught at (%d,%d)\n", i + 1, ball.x, ball.y);
    }
    return 0;
}
