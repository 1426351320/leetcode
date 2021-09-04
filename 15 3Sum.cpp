#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
    typedef vector<int>::iterator vecite;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        if (nums.empty())
            return ret;
        sort(nums.begin(), nums.end());
        for (vecite ite = nums.begin(); ite != nums.end(); ite++) {
            if (ite != nums.begin() && *ite == *(ite - 1))
                continue;
            int sum = -*ite;
            vecite first = ite + 1, last = nums.end() - 1;
            while (first < last) {
                if (*first + *last == sum) {
                    ret.push_back({*ite, *first, *last});
                    sort(ret.begin(), ret.end());
                    first++;
                    last--;
                } else if (sum - *first < *last)
                    last --;
                else if (sum - *first > *last)
                    first ++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> input = {-2,0,0,2,2};
    sol.threeSum(input);
    return 0;
}