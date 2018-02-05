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

#define MAXN 100005

struct nodo{
    int max1, max2;
    nodo() { }
}T[MAXN*4];

struct point{
    int pos, val;
    point(int x, int y)
    {
        pos = x; val = y;      
    }
    bool operator<(const point &other)const
    {
        return other.val < val;
    }
};

int n, v[MAXN];
int dp[MAXN];

void update(int b, int e, int node, int i, int val)
{
    if(i < b || i > e) return;

    if(b == e) T[node].max1 = b, T[node].max2 = -1;
    else
    {
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
        
        update(b, mid, le, i, val);
        update(mid + 1, e, ri, i, val);
        
        vector<point> p;
        p.push_back(point(T[le].max1, v[T[le].max1]));
        p.push_back(point(T[le].max2, v[T[le].max2]));
        p.push_back(point(T[ri].max1, v[T[ri].max1]));
        p.push_back(point(T[ri].max2, v[T[ri].max2]));
        sort(ALL(p));
        
        T[node].max1 = p[0].pos; 
        T[node].max2 = p[1].pos; 
    }
}

void init(int b, int e, int node)
{
    if(b == e) T[node].max1 = b, T[node].max2 = -1;
    else
    {
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
        init(b, mid, le);
        init(mid + 1, e, ri);
        
        vector<point> p;
        p.push_back(point(T[le].max1, v[T[le].max1]));
        p.push_back(point(T[le].max2, v[T[le].max2]));
        p.push_back(point(T[ri].max1, v[T[ri].max1]));
        p.push_back(point(T[ri].max2, v[T[ri].max2]));
        sort(ALL(p));
        
        T[node].max1 = p[0].pos; 
        T[node].max2 = p[1].pos; 
    }
}

nodo query(int b, int e, int node, int i, int j)
{
    if(i <= b && e <= j){
         return T[node];
    }
    
    int mid = (b + e) / 2, le = 2*node + 1, ri = 2*node + 2;
    
    if(j <= mid) return query(b, mid, le, i, j);
    else if(mid < i) return query(mid + 1, e, ri, i, j);
    else
    {
        nodo ret1 = query(b, mid, le, i, j);
        nodo ret2 = query(mid + 1, e, ri, i, j);
        
        vector<point> p;
        p.push_back(point(ret1.max1, v[ret1.max1]));
        p.push_back(point(ret1.max2, v[ret1.max2]));
        p.push_back(point(ret2.max1, v[ret2.max1]));
        p.push_back(point(ret2.max2, v[ret2.max2]));
        sort(ALL(p));
        
        nodo ret;
        ret.max1 = p[0].pos; 
        ret.max2 = p[1].pos; 

        return ret;
    }
}

int main()
{
    // numero de valores a ingresar
	scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    v[n + 1] = -1;
    // inicializar segment tree
    init(0, n-1, 0);
    
    //numero de querys
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int x, y;
        char c;
        cin >> c >> x >> y;
        //printf("%c %d %d", c, x, y);
        // 1 b c -> Imprimir suma y minimo de los elementos del rango b...c
        if(c == 'U'){
            --x;
            v[x] = y;
            update(0, n-1, 0, x, y);
        }
        else
        {
            --x, --y;
            nodo r = query(0, n - 1, 0, x, y);
            printf("%d\n", v[r.max1] + v[r.max2]);
        }
    }
    
	return 0;
}
