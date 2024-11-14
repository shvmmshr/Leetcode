class Solution {
public:
    bool canDistribute(int n, vector<int>& quantities, int maxPerStore) {
        int storesNeeded = 0;
        for (int quantity : quantities) {
            storesNeeded += (quantity + maxPerStore - 1) / maxPerStore;
            if (storesNeeded > n) return false;
        }
        return storesNeeded <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(n, quantities, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};