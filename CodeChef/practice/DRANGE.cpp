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
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 2000000000
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
  
#define MAXN 1000001
  
struct nodo{ 
    int mx, mn;
    int lazy;
    nodo() { } 
}T[MAXN*4]; 
  
int a[MAXN];
int action;
int n, x, y;

void init(int b, int e, int node)
{ 
    if(b == e) T[node].mn = T[node].mx = a[b], T[node].lazy = 0; 
    else
    { 
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2; 
        init(b, mid, le); 
        init(mid + 1, e, ri); 

        T[node].mn = min(T[le].mn, min(T[ri].mn, min(T[le].mx, T[ri].mx))); 
        T[node].mx = max(T[le].mn, max(T[ri].mn, max(T[le].mx, T[ri].mx)));
        T[node].lazy = 0;
    } 
} 

void update(int b, int e, int node)
{
    int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
    //printf("%d %d node=%d mx=%d mn=%d lazy=%d\n", b, e, node, T[node].mx, T[node].mn, T[node].lazy);SP;
    if(T[node].lazy){
        // propagate lazy action
        if(b != e){
            T[le].lazy += T[node].lazy;
            T[ri].lazy += T[node].lazy;
        }
        
        // apply lazy action on itself
        T[node].mn += T[node].lazy;
        T[node].mx += T[node].lazy;
        
        // this node has no lazy action to propagate
        T[node].lazy = 0;
    }
    
    if(e < x || y < b) return;
    
    if(x <= b && e <= y){
        // update
        T[node].mn += action;
        T[node].mx += action;
        
        if(b != e){
             T[le].lazy += action;
             T[ri].lazy += action;
        }
        
        //printf("[%d, %d] mx=%d mn=%d\n", b, e, T[node].mx, T[node].mn);
        return;
    }
    else{
        update(b, mid, le);
        update(mid + 1, e, ri);
        //printf("%d %d mid=%d\n", b, e, mid);
        //printf("[%d, %d] mx=%d mn=%d\n", b, mid, T[le].mx, T[le].mn);
        //printf("[%d, %d] mx=%d mn=%d\n", mid + 1, e, T[ri].mx, T[ri].mn);
        T[node].mn = min(T[le].mn, min(T[ri].mn, min(T[le].mx, T[ri].mx))); 
        T[node].mx = max(T[le].mn, max(T[ri].mn, max(T[le].mx, T[ri].mx)));
        //printf("UPDATE [%d, %d] mx=%d mn=%d\n", b, e, T[node].mx, T[node].mn);
    }
}

void print(int b, int e, int node, int sp){
     printf("%*s", sp, "");
     printf("[%d, %d] mx=%d mn=%d lazy=%d\n", b, e, T[node].mx, T[node].mn, T[node].lazy);
     if(b != e){
          int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
          print(b, mid, le, sp + 4);
          print(mid + 1, e, ri, sp + 4);
     }
}

int main() 
{
    int cas;
    int m, z; 
    scanf("%d", &cas);
    while(cas--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i)
            a[i] = i + 1;
        
        init(0, n - 1, 0);
        //print(0, n - 1, 0, 0);
        
        F(i, m){
             scanf("%d%d%d%d", &z, &x, &y, &action);
             if(action == 0) continue;
             --x; --y;
             if(z == 2) action *= -1, update(0, n - 1, 0);
             else if(z == 1) update(0, n - 1, 0);
             //print(0, n - 1, 0, 0);
             //printf("> %d %d\n", T[0].mx, T[0].mn);
        }
        printf("%d\n", T[0].mx - T[0].mn);
    }
    return 0; 
}
