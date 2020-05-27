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

class LinkedList {
public: 
	Node *head;
	LinkedList() {
		head = NULL;
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

	void print() {
		Node *it = head;
		while (it) {
			cout << it->value << " -> ";
			it = it->next;
		}
		cout << endl;
	}
};

void insert_node(Node *&head, Node *&tail, Node *n) {
	if (!head) {
		head = tail = n;
	} else {
		tail->next = n;
		tail = tail->next;
	}
}

// main method
void merge(LinkedList l1, LinkedList l2) {
	Node *it1 = l1.head;
	Node *it2 = l2.head;
	Node *head = NULL;
	Node *tail = NULL;
	while (it1 && it2) {
		if (it1->value < it2->value) {
			insert_node(head, tail, it1);
			it1 = it1->next;
		} else {
			insert_node(head, tail, it2);
			it2 = it2->next;
		}
	}

	while (it1) {
		insert_node(head, tail, it1);
		it1 = it1->next;
	}
	while (it2) {
		insert_node(head, tail, it2);
		it2 = it2->next;
	}

	l1.head = head;
}


int main() {
	LinkedList l1;
	l1.insert(2);
	l1.insert(5);
	l1.insert(7);
	l1.print();

	LinkedList l2;
	l2.insert(3);
	l2.insert(11);
	l2.print();

	merge(l1, l2);
	l1.print();
	cout << "END" << endl;
	return 0;
}