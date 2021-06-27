#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int buyDay = -1;
    int profit = 0;
    int size = prices.size();
    if (1 <= size && size <= 3 * pow(10.0, 4.0)) {
      for (int i = 0; i < size; i++) {
        if (0 <= prices[i] && prices[i] <= pow(10.0, 4.0)) {
          if (buyDay != -1) {
            if (prices[buyDay] < prices[i]) {
              if (size - 1 != i) {
                if (prices[i] > prices[i + 1]) {
                  profit += prices[i] - prices[buyDay];
                  buyDay = -1;
                } else {
                  continue;
                }
              } else {
                profit += prices[i] - prices[buyDay];
              }
            }
          }
          if (size - 1 != i) {
            if (prices[i] < prices[i + 1]) {
              buyDay = i;
            }
          }
        }
      }
      return profit;
    } else {
      return -1;
    }
  }
};

int main() {
  Solution s;

  vector<vector<int>> testCases{
      {7, 1, 5, 3, 6, 4}, {1, 2, 3, 4, 5}, {7, 6, 4, 3, 1}, {1}, {1, 2},
  };

  for (int i = 0; i < testCases.size(); i++) {
    cout << s.maxProfit(testCases[i]);
    cout << endl;
  }
}