#include <iostream>

using namespace std;

class KMP {
public:
  KMP(const string& pattern)
    : failure_(new int[pattern.size() + 1]), pattern_(pattern) {
    // build failure function
    failure_[0] = failure_[1] = 0;

    for (int i = 2; i <= pattern_.size(); ++i) {
      for (int j = failure_[i - 1]; ; j = failure_[j]) {
        if (pattern_[j] == pattern_[i - 1]) { failure_[i] = j + 1; break; }
        if (j == 0) { failure_[i] = 0; break; }
      }
    }
  }

  ~KMP() { delete[] failure_; }

  int Match(const string& text) {
    for (int i = 0, j = 0; ;) {
      if (j == text.size()) return i;

      if (text[j] == pattern_[i]) {
        ++i, ++j;
      } else if (i > 0) {
        i = failure_[i];
      } else {
        ++j;
      }
    }
  }

private:
  int *failure_;
  string pattern_;
};

int main() {
  string s;
  while (cin >> s) {
    string s_rev(s.rbegin(), s.rend());
    KMP kmp(s_rev);
    int max_match = kmp.Match(s);
    cout << (s + s_rev.substr(max_match)) << endl;
  }
}
