class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        deque<int> dq;
        int min_length = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefix_sum[i] - prefix_sum[dq.front()] >= k) {
                min_length = min(min_length, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix_sum[i] <= prefix_sum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        return min_length == INT_MAX ? -1 : min_length;
    }
};