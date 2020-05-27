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

class Queue {
public:
	vector<int> v;
	int size;
	int elements;
	int head, tail;

	Queue(int _size) {
		size = _size;
		v = vector<int>(size);
		head = tail = 0;
		elements = 0;
	}

	void enqueue(int value) {
		int new_tail = (tail + 1) % size;
		if (new_tail == head) {
			v.insert(v.begin() + tail, value);
			size += 1;
			if (tail < head) {
				head = (head + 1) % size;
			}
			tail = (tail + 1) % size;
		} else {
			v[tail] = value;
			tail = new_tail;
		}
		assert(tail < size);
		assert(head < size);
		++elements;
	}

	int dequeue() {
		if (!elements) {
			throw string("there're no elements");
		}
		int to_return = v[head];
		head = (head + 1) % size;
		--elements;
		return to_return;
	}
};

int main() {
	Queue q(2);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << q.dequeue() << endl;
	q.enqueue(4);
	cout << q.dequeue() << endl;
	q.enqueue(4);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	return 0;
}