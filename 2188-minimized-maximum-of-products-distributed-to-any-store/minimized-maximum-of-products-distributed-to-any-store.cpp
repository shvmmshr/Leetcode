class Solution {
public:
    bool canDist(int n, vector<int>& quantities, int maxPer) {
        int stores = 0;
        for (int q : quantities) {
            stores += (q + maxPer - 1) / maxPer;
            if (stores > n) return false;
        }
        return stores <= n;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDist(n, quantities, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
