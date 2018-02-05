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
#define IMAX 2147483647
typedef long long LL;
using namespace std;
int w[25];
int main(){
    int n, k;
    double avg;
    while(cin >> n){
        avg = 0.0;
        int sum = 0;
        F(i, n){
            cin >> w[i];
            avg += w[i];
            sum += w[i];
        }
        avg /= 2.0;
        sort(w, w + n);

        int pile = 0;
        for(int i = n - 1; i >= 0; --i){
            if(pile + w[i] <= avg)
                pile += w[i];
        }
        printf("%d\n", abs(pile - (sum - pile)));
    }
    return 0;
}
