#include "test_framework/generic_test.h"

void fact(unordered_map<int, int> &coeff, int t, int op) {
    for (int j = 2; j <= sqrt(t); j += 1) {
        while (t % j == 0 && t) {
            t /= j;
            coeff[j] += op;
        }
    }
    if (t) {
        coeff[t] += op;
    }
}

int ComputeBinomialCoefficient(int n, int k) {
    unordered_map<int, int> coeff;
    int den = min(n - k, k);
    int num = n - den + 1;
    for (int i = num; i <= n; i += 1) {
        fact(coeff, i, 1);
    }
    for (int i = 2; i <= den; i += 1) {
        fact(coeff, i, -1);
    }
    int mult = 1;
    for (auto & it : coeff) {
        mult *= pow(it.first, it.second);
    }
    return mult;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  return GenericTestMain(
      args, "binomial_coefficients.cc", "binomial_coefficients.tsv",
      &ComputeBinomialCoefficient, DefaultComparator{}, param_names);
}
