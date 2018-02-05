class Trie {
public:
    struct Node {
        unordered_map<char, Node*> next;
        vector<int> v;
        Node() {}
    };

    Node *root;

    Trie() {
        root = new Node();
    }

    void insert(string s, int index) {
        Node *it = root;
        it->v.push_back(index);
        for(int i = 0; i < s.size(); i += 1) {
            if (it->next.find(s[i]) == it->next.end()) {
                it->next[s[i]] = new Node();
            }
            it = it->next[s[i]];
            it->v.push_back(index);
        }
    }

    vector<int> find(string s) {
        Node *it = root;
        if (!s.size()) return it->v;
        for(int i = 0; i < s.size(); i += 1) {
            if (it->next.find(s[i]) == it->next.end()) {
                return vector<int>();
            }
            it = it->next[s[i]];
        }
        return it->v;
    }
};

class WordFilter {
public:
    Trie *ltor, *rtol;

    WordFilter(vector<string> words) {
        ltor = new Trie();
        rtol = new Trie();
        for (int i = 0; i < words.size(); i += 1) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            ltor->insert(words[i], i);
            rtol->insert(rev, i);
        }
    }

    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        vector<int> left = ltor->find(prefix);
        vector<int> right = rtol->find(suffix);
        for (int i = left.size() - 1; i >= 0; i -= 1) {
            if (binary_search(right.begin(), right.end(), left[i])) return left[i];
        }
        return -1;
    }
};

