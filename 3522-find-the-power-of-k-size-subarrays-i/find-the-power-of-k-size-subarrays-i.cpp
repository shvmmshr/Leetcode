#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results(n - k + 1, -1);

        for (int i = 0; i <= n - k; ++i) {
            bool isConsecutive = true;
            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j] + 1 != nums[j + 1]) {
                    isConsecutive = false;
                    break;
                }
            }
            if (isConsecutive) {
                results[i] =
                    *max_element(nums.begin() + i, nums.begin() + i + k);
            }
        }

        return results;
    }
};