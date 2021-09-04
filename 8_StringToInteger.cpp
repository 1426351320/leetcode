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
  vector<int> findAnagrams(string s, string p) {
    int count = p.size();
    vector<int> ret;
    unordered_map<char, int> index;

    for (auto i : p)
      index[i]++;

    for (int begin = 0, end = 0; end < s.size();) {
      if (index[s[end++]]-- > 0)
        count--;
      if (end - begin >= p.size() && index[s[begin++]]++ >= 0)
        count++;
      if (!count)
        ret.push_back(begin);
    }

    return ret;
  }
};

int main() {
  Solution sol;

  sol.findAnagrams("cbaebabacd", "abc");

  return 0;
}