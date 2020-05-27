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

struct File {
	int t;
	int filename_index;
	int current_line;
	string record;
	File() {}
	bool operator<(const File &other) const {
		return t > other.t;
	}
};

File read_line(string filename, int index, int n) {
	// reads the n-th line of the file
	File file;
	file.t = 
	file.filename_index = index;
	file.current_line = n;
	file.record = readLine(filename, n);
	return file;
}

void write_line(string filename, string data) {
	// appends data to the file filename
}

void solve(vector<string> &path, string dest) {
	// initial read of each line of each path
	priority_queue<File> pq;

	for (int i = 0; i < path.size(); i += 1) {
		// read file		
		pq.push(readLine(path[i], i, 0));
	}

	while (!pq.empty()) {
		File top = pq.top();
		pq.pop();
		write_line(dest, top.record);
		pq.push(readline(
			path[top.filename_index],
			top.filename_index,
			top.current_line + 1
		));
	}
}

int main() {
	
	return 0;
}