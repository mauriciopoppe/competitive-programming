#include <string>

#include "test_framework/generic_test.h"
using std::string;

bool CanFormPalindrome(const string& s) {
  map<char, int> cnt;
  for (int i = 0; i < s.size(); i += 1) {
    cnt[s[i]]++;
  }
  int odd = 0;
  for (auto &v: cnt) {
    if (v.second % 2 == 1) odd++;
  }
  return odd <= 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_string_permutable_to_palindrome.cc",
                         "is_string_permutable_to_palindrome.tsv",
                         &CanFormPalindrome, DefaultComparator{}, param_names);
}
