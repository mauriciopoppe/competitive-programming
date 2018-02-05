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
#define E 0.5
#define M 101
#define X 0
#define Y 1
#define pow2(a) ((a)*(a))

int rgb[M][3];
int s[M][3];
int is_circle[M];
char w[500];

int round_own(double r, double ct)
{
    r = (double)r / (double)ct;
    r += 0.5;
    int rr = (int) r;
    return rr;    
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    int x, y, q, n;
    scanf("%d", &cas);
    F(z, cas)
    {
        if(z)NL; 
        scanf("%d%d", &n, &q);
        int cc = 0, sc = 0;
        
        for(int i = 0; i < n; ++i)
           is_circle[i] = 0;
                
        for(int i = 0; i < n; ++i)
        {
            scanf("%s%d%d%d%d%d%d", w, &s[i][X], &s[i][Y], &s[i][2], 
                                    &rgb[i][0], &rgb[i][1], &rgb[i][2]);
            if(w[0] == 'C')
               is_circle[i] = 1;
        }
        
        printf("Case %d:\n", z + 1);
        for(int i = 0; i < q; ++i)
        {                
            scanf("%d%d", &x, &y);    
            int ct = 0, r = 0, g = 0, b = 0;
            for(int k = 0; k < n && ct >= 0; ++k)
            {                    
                //printf("%d %d %d\n", rgb[k][0], rgb[k][1], rgb[k][2]);
                if(is_circle[k])
                {
                    int res = pow2(x - s[k][X]) + pow2(y - s[k][Y]) - pow2(s[k][2]);
                    //printf("%d\n", res);
                    if(res < 0)
                    {
                        r += rgb[k][0]; 
                        g += rgb[k][1]; 
                        b += rgb[k][2];                         
                        ++ct;
                    }
                    else if(res == 0)
                      ct = -1;
                }
                else
                {
                    int dx1 = s[k][X] + s[k][2] - x;
                    int dx2 = x - s[k][X];
                    int dy1 = s[k][Y] + s[k][2] - y;
                    int dy2 = y - s[k][Y];
                    
                    if(dx1 >= 0 && dx2 >= 0 && dy1 >= 0 && dy2 >= 0)
                    {
                        if(dx1 == 0 || dx2 == 0 || dy1 == 0 || dy2 == 0)
                        {
                            ct = -1;
                            continue;
                        }
                        r += rgb[k][0];
                        g += rgb[k][1]; 
                        b += rgb[k][2];
                        ++ct;
                    }
                    
                }
            }
            //printf("%d %d %d\n", r, g, b);
            if(ct < 0)
               puts("(0, 0, 0)");
            else if(ct == 0)
               puts("(255, 255, 255)");
            else
                printf("(%d, %d, %d)\n", round_own(r, ct), round_own(g, ct), round_own(b, ct));
        }
    }
    return 0;
}
