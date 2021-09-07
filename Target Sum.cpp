#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < target || sum + target < 0 || (sum + target) % 2)
      return 0;

    vector<int> dp((sum + target) / 2 + 1, 0);

    dp[0] = 1;
    for (auto num : nums) {
      for (int j = dp.size() - 1; j >= num; j--)
        dp[j] += dp[j - num];
    }

    return dp.back();
  }
};

int main() {
  Solution sol;
  vector<int> vec{100};

  cout << sol.findTargetSumWays(vec, -200);

  return 0;
}