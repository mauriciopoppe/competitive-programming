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

void print(Node *head) {
	Node *it = head;
	while (it) {
		cout << it->value << " -> ";
		it = it->next;
	}
	cout << endl;
}

Node *find_cycle_helper(Node *&head) {
	Node *slow = head;
	Node *fast = head;
	while (slow && slow->next && fast && fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			// cycle found at a distance k from cycle start
			int cycle_length = 0;
			do {
				slow = slow->next;
				cycle_length += 1;
			} while (slow != fast);

			// find the beginning of the cycle
			slow = head;
			fast = head;
			while (cycle_length) {
				fast = fast->next;
				--cycle_length;
			}

			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return NULL;
}

void solve(Node *&head) {
	Node *cycle = find_cycle_helper(head);
	if (cycle) {
		cout << cycle->value << endl;
	} else {
		cout << "no cycle found" << endl;
	}
}

int main() {
	Node *head = NULL;
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);
	print(head);
	solve(head);
	head->next->next->next->next = head->next->next;
	solve(head);
	return 0;
}