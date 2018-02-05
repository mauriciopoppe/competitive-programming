#include <stdio.h>
#include <set>
 
using namespace std;
 
#define REP(i,n) for (int i=0,_n=n; i<_n; i++)
 
#define MAXN 20000
 
multiset<int> H;
int D[MAXN], n;
 
bool pay(){
  int cost = 0;
  REP(i,n){
    multiset<int>::iterator j = H.lower_bound(D[i]); // find the knight
    if (j == H.end()) return false; // no knight found
    cost += *j; // accumulate the cost of using the knight
    H.erase(j); // remove the knight
  }
  printf("%d\n",cost);
  return true;
}
 
int main(){
  for (int m,h; scanf("%d %d",&n,&m)!=EOF && (n || m); ){
    H.clear();
    REP(i,n) scanf("%d",&D[i]);
    REP(i,m) scanf("%d",&h), H.insert(h);
    if (!pay()) puts("Loowater is doomed!");
  }
}
