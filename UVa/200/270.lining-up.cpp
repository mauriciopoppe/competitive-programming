#include <stdio.h>
#include <algorithm>
using namespace std;
struct point{
       int x, y;
       bool operator<(const point &other)const
       {
           if(x != other.x)
              return x < other.x;
           return y < other.y;  
       }
} p[701];

char w[25];
int n, i, j, k;
int a, b, c;
int solve()
{
    if(n <= 2)
       return n;
    sort(p, p + n);
    int mx = 0;
    for(i = 0; i < n; ++i)
        for(j = i + 1; j < n; ++j)
        {
            int cnt = 0;  
            a = p[i].y - p[j].y;
            b = p[i].x - p[j].x;
            c = p[j].y * b - p[j].x * a;
            for(k = 0; k < n; ++k)
               if(p[k].x * a - p[k].y * b + c == 0)
                  ++cnt;
            mx = max(mx, cnt);
        }
    return mx;
}

int main()
{
	int t;
	for (scanf("%d", &t); t-- > 0;) 
    {
		for (n = 0; gets(w);) 
        {
			if (sscanf(w, "%d %d", &p[n].x, &p[n].y) == 2)
				++n;
			else if (n != 0)
				break;
		}
		printf(t ? "%d\n\n" : "%d\n", solve());
	}

	return 0;
}
