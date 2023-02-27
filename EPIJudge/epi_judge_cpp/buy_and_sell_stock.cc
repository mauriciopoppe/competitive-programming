#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  // TODO - you fill in here.

  double mn = prices[0];
  double best = 0;
  for (int i = 0; i < prices.size(); i += 1) {
    if (prices[i] - mn > best) {
      best = prices[i] - mn;
    }

    if (prices[i] < mn) {
      mn = prices[i];
    }
  }

  return best;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
