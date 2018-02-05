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
	Node *next, *jump;
	Node(int _value) {
		next = jump = NULL;
		value = _value;
	}

	Node *clone_self() {
		return new Node(value);
	}

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
};

struct LinkedList {
	Node *head;

	LinkedList() {
		head = NULL;
	}

	LinkedList(Node *_head) {
		head = _head;
	}

	void insert(int v) {
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

	Node *find(int value) {
		Node *it = head;
		while (it) {
			if (it->value == value) {
				return it;
			}
			it = it->next;
		}
		return NULL;
	}

	void jump(int from, int to) {
		Node *node_from = find(from);
		Node *node_to = find(to);
		node_from->jump = node_to;
	}

	Node *clone() {
		Node *it = head;
		while (it) {
			Node *copy = it->clone_self();
			Node *next = it->next;
			it->next = copy;
			copy->next = next;
			it = next;
		}

		// create the jump links between the new nodes
		it = head;
		while (it) {			
			Node *jump = it->jump->next;
			it->next->jump = jump;
			it = it->next->next;
		}

		// fix the missing links
		it = head;
		Node *head_clone = NULL;
		if (it) {
			head_clone = it->next;
		}
		while (it) {
			Node *original_next = it->next->next;
			Node *it_clone = it->next;
			if (original_next) {
				it_clone->next = original_next->next;				
			} else {
				it_clone->next = NULL;
			}
			it->next = original_next;
			it = it->next;
		}
		return head_clone;
	}

	void print() {
		Node *it = head;
		while (it) {
			cout << it->value << ":";
			if (it->jump) {
				cout << it->jump->value;	
			} else {
				cout << "NOJUMP";
			}
			cout << " -> ";
			it = it->next;
		}
		cout << endl;
	}
};

int main() {
	LinkedList l;
	l.insert(5);
	l.insert(9);
	l.insert(7);
	l.insert(6);
	l.jump(5, 9);
	l.jump(9, 6);
	l.jump(7, 9);
	l.jump(6, 6);
	l.print();
	LinkedList cloned(l.clone());
	cloned.print();
	return 0;
}