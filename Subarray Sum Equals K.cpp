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
  int subarraySum(vector<int> &nums, int k) {

    // dp represents the times that i appear while accumulate
    unordered_map<int, int> dp;
    int ret(0), sum(0);

    dp[0] = 1;
    for (int i(0); i < nums.size(); i++) {
      sum += nums[i];
      if (dp.find(sum - k) != dp.end())
        ret += dp[sum - k];
      dp[sum]++;
    }

    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> vec{1, -1, 0};

  cout << sol.subarraySum(vec, 0);

  return 0;
}