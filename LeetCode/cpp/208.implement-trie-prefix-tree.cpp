class Trie {
public:
    struct Node {
        map<char, Node*> m;
        char v;
        int n;
        Node(char c) {
            v = c;
            n = 0;
        }
    };
    Node *head;
    
    /** Initialize your data structure here. */
    Trie() {
        head = new Node('*');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *it = head;
        for (char c: word) {
            if (!it->m.count(c)) {
                it->m[c] = new Node(c);
            }
            it = it->m[c];
        }
        it->n++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *it = head;
        for (char c: word) {
            if (!it->m.count(c)) return false;
            it = it->m[c];
        }
        return it->n > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *it = head;
        for (char c: prefix) {
            if (!it->m.count(c)) return false;
            it = it->m[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
