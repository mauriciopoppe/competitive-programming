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

vector<vector<int> > l, g;

void solve(string &a, string &b) {
	cout << "- ";
	for (int i = 0; i < a.size() - 1; i += 1) {
		if (a[i] != b[i]) {
			if (b[i] == '1') {
				cout << "Switch on light in room " << (i + 1) << "." << endl;
			} else {
				cout << "Switch off light in room " << (i + 1) << "." << endl;
			}
			return;
		}
	}
	cout << "Move to room " << (b[b.size() - 1] - '0' + 1)  << "." << endl;
}

/**
 * Breadth first search algorithm applied on an unweighted graph `G`
 * of order `n` and size `m` to find the shortest path from a source
 * vertex
 *
 * Time complexity: O(n + m)
 * Space complexity: O(n)
 *
 * @param {vector<vector<pair<int, int> > >} g The adjacency list representation
 *  of `G`, each entry `g_{ij}` holds the end `v` of the edge `iv`
 * @param {int} s The source vertex
 * @return {vector<int>} The shortest path from `s` to all the other vertices
 */
void bfs() {
	int n = g.size();
	string source(n, '0');
	source[0] = '1';
	source += '0';

	string target(n, '0');
	target[n - 1] = '1';
	target += (char) (n - 1 + '0');
	
  map<string, int> d;
  map<string, string> parent;

  // cout << source << " " << target << endl;;

  // the estimated distance from the source vertex is zero
  d[source] = 0;

  // accumulated weight, next vertex (weight, v)
  queue<string> q;
  q.push(source);

  while (!q.empty()) {
    string top = q.front();
    q.pop();

    // cout << top << endl;

    if (top == target) {
    	break;
    }

    int room = top[n] - '0';

    // rooms
    for (int i = 0; i < g[room].size(); i += 1) {
    	int to = g[room][i];
    	if (top[to] == '1') {
    		string new_state = top;
    		new_state[n] = (char)(to + '0');
    		if (!d.count(new_state)) {
    			d[new_state] = d[top] + 1;
    			parent[new_state] = top;
    			q.push(new_state);
    		}
    	}
    }

    // lights
    for (int i = 0; i < l[room].size(); i += 1) {
    	int to = l[room][i];
  		string new_state = top;
  		if (to == room) {
  			continue;
  		}
  		if (new_state[to] == '1') {
  			new_state[to] = '0';
  		} else {
  			new_state[to] = '1';
  		}
  		if (!d.count(new_state)) {
  			d[new_state] = d[top] + 1;
  			parent[new_state] = top;
  			q.push(new_state);
  		}
    }
  }

  if (!d.count(target)) {
  	cout << "The problem cannot be solved." << endl;
  	return;
  }

  vector<string> solution;

  string back = target;
  while (parent.count(back)) {
  	solution.push_back(back);
  	back = parent[back];
  }
  solution.push_back(back);

  reverse(solution.begin(), solution.end());

  printf("The problem can be solved in %d steps:\n", solution.size() - 1);
  for (int i = 1; i < solution.size(); i += 1) {
  	solve(solution[i - 1], solution[i]);
  }
}

int main() {
	int n, edges, lights;
	int cas = 0;
	while (cin >> n >> edges >> lights) {
		if (n == 0 && edges == 0 && lights == 0) {
			break;
		}
		
		g.assign(n, vector<int>());
		l.assign(n, vector<int>());

		int from, to;
		for (int i = 0; i < edges; i += 1) {
			cin >> from >> to;
			from--;
			to--;
			g[from].push_back(to);
			g[to].push_back(from);
		}

		for (int j = 0; j < lights; j += 1) {
			cin >> from >> to;
			from--;
			to--;
			l[from].push_back(to);
		}

		printf("Villa #%d\n", ++cas);
		bfs();
		NL;
	}
	return 0;
}