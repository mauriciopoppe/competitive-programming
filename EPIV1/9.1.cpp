#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

class Stack {
public:
	stack<pair<int, int> > self;

	void push(int v) {
		if (self.empty()) {
			self.push(pair<int, int>(v, v));
		} else {
			self.push(pair<int, int>(v, ::max( self.top().second, v )));
		}
	}

	int max() {
		if (self.empty()) {
			throw string("There're no values on the stack");
		} 
		return self.top().second;
	}

	void pop() {
		if (self.empty()) {
			throw string("There're no values on the stack");			
		}
		self.top().second;
		self.pop();
	}
};

int main() {
	Stack s;
	s.push(2);
	cout << s.max() << endl;
	s.push(7);
	cout << s.max() << endl;
	s.push(3);
	cout << s.max() << endl;
	s.push(5);
	cout << s.max() << endl;
	s.pop();
	cout << s.max() << endl;
	s.pop();
	cout << s.max() << endl;
	s.pop();
	cout << s.max() << endl;
	s.pop();
	// cout << s.max() << endl;	
	return 0;
}