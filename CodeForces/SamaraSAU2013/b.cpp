#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
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
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct node {
       int cnt;
       map<char, node*> edges;
       node() {
           cnt = 0;
       }
} *root;
 
int insert_word(string q) {
    node *ptr = root;  
    for(int i = 0; q[i]; ++i) {
    	//if there's no edge, build the edge  
        if(ptr->edges.find(q[i]) == ptr->edges.end())
            ptr->edges[q[i]] = new node();
 
        //advance to the next node
        ptr = ptr->edges[q[i]];
    }
    //flag that states that a word ends here
    ptr->cnt++;
    return ptr->cnt - 1;
}

char word[1000010];

string transform(char *w) {
	map<char, int> m;
	int start = 1;
	string t = "";
	for (int i = 0; w[i]; ++i) {
		if (!m[w[i]]) {
			m[w[i]] = start++;
		}
		t += m[w[i]] + '0';
	}
	return t;
}

int main() {
	int n;	
	while (cin >> n) {
		LL total = 0;
		root = new node();
		F(i, n) {
			scanf("%s", word);
			total += insert_word(transform(word));
		}
		cout << total << endl;
	}
	return 0;
}