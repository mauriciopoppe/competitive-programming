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
using namespace std;

#define MAXN 10000000

struct node{
    int ontop;
    node *L;
    node *R;
    node(){
        ontop = 0;
        R = L = NULL;
    }
};

int a[40001][2];
int LEFT, RIGHT;

int update(int begin, int end, node *root){
     if(root->ontop == 1)
        return 0;
        
     if(LEFT <= begin && end <= RIGHT){
        return root->ontop = 1;
     }
     
     int mid = (begin + end) >> 1;
     if(root->L == NULL)root->L = new node();
     if(root->R == NULL)root->R = new node();
     
     int ret = -1;
     if(RIGHT <= mid)
         ret = update(begin, mid, root->L);
     else if(LEFT > mid)
         ret = update(mid + 1, end, root->R);
     else{
         int L = update(begin, mid, root->L);
         int R = update(mid + 1, end, root->R);         
         ret = L | R;
     }
     root->ontop = root->L->ontop & root->R->ontop;
     return ret;
}

int cnt;
void print(int begin, int end, node *root){
     printf("(%d,%d)%d\n", begin, end, root->ontop);
     int mid = (begin + end) >> 1;
     if(root->L != NULL)
         print(begin, mid, root->L);     
     if(root->R != NULL)
         print(mid + 1, end, root->R);
}

int main()
{
    int cas, n; 
    scanf("%d", &cas);
    while(cas--){                 
    	scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &a[i][0], &a[i][1]);
        
        int total = 0;
        int BEGIN = 0, END = MAXN - 1;
        node *root = new node();
        for(int i = n - 1; i >= 0; --i){
            LEFT = a[i][0] - 1;
            RIGHT = a[i][1] - 1;
            total += update(BEGIN, END, root);
            //print(0, MAXN - 1, root);NL;
        }
        printf("%d\n", total);
    }
	return 0;
}
