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

struct Node {
	int value;
	Node *next;
	Node(){}
	Node(int _value) {
		value = _value;
		next = NULL;
	}
};

void insert(Node *&head, int v) {
	Node *newValue = new Node(v);
	if (!head) {
		head = newValue;
	} else {
		Node *it = head;
		while (it->next) {
			it = it->next;
		}
		it->next = newValue;
	}
}

void reverse(Node *&head) {
	Node *it = head;
	Node *next;
	Node *newHead = NULL;
	while (it) {
		next = it->next;
		it->next = newHead;
		newHead = it;
		it = next;
	}
	head = newHead;
}

void print(Node *head) {
	Node *it = head;
	while (it) {
		cout << it->value << " -> ";
		it = it->next;
	}
	cout << endl;
}

int main() {
	Node *head = NULL;
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	print(head);
	reverse(head);
	print(head);
	return 0;
}