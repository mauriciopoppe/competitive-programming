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

#define MAXN 100004

struct nodo{
    int height;
    int unified;
    nodo() { 
        height = 0;
        unified = 1;
    }
}T[MAXN*4];

int LEFT, RIGHT;

void init(int b, int e, int node)
{
    if(b == e) T[node].height = 0, T[node].unified = 1;
    else
    {
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
        init(b, mid, le);
        init(mid + 1, e, ri);
        
        T[node].height = 0;
        T[node].unified = 1;
    }
}

int update(int b, int e, int node, int new_height)
{
    if(RIGHT < b || LEFT > e) return 0;
//    printf("%d %d [%d %d]\n", b, e, LEFT, RIGHT);SP;
    
    if(LEFT <= b && e <= RIGHT && T[node].unified == 1){
        int diff = 0;
        if(new_height >= T[node].height)
            diff = e - b + 1;
        T[node].height = max(T[node].height, new_height);
        //printf("IN %d %d h=%d diff=%d\n", b, e, T[node].height, diff);SP;
        return diff;
    }
    
    if(b != e){
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
        
        //propagate if unified
        if(T[node].unified){
            T[le].unified = T[ri].unified = 1;
            T[le].height = T[ri].height = T[node].height;
        }
        
        int L = update(b, mid, le, new_height);
        int R = update(mid + 1, e, ri, new_height);
        
        T[node].unified = T[le].height == T[ri].height && (T[le].unified & T[ri].unified);
        if(T[node].unified)
            T[node].height = T[le].height;
        //printf("UPDATE %d %d h=%d u=%d\n", b, e, T[node].height, T[node].unified);SP;
        return L + R;
    }
    
    return -1000;
}

void print(int b, int e, int node){
     printf("(%d,%d)h = %d, u = %d\n", b, e, T[node].height, T[node].unified);
     if(b == e)return;
     int mid = (b + e) >> 1;
     print(b, mid, node * 2 + 1);
     print(mid + 1, e, node * 2 + 2);
}

int main()
{
    int cas, n, height;
    scanf("%d", &cas);
    while(cas--){
    	scanf("%d", &n);
    	int total = 0;
        init(0, MAXN - 1, 0);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &LEFT, &RIGHT, &height);
            LEFT -= 1;
            RIGHT -= 2;
            int upd = update(0, MAXN - 1, 0, height); 
            total += upd;
        }
        printf("%d\n", total);
    }
	return 0;
}
