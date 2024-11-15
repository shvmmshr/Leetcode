class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) left++;
        if (left == n - 1) return 0;
        
        int right = n - 1;
        while (right > left && arr[right - 1] <= arr[right]) right--;
        
        int mini = min(n - left - 1, right);
        for(int i = 0; i <= left; i++){
            int j = lower_bound(arr.begin() + right, arr.end(), arr[i]) - arr.begin();
            mini = min(mini, j - i - 1);
            if(j == n) break;
        }
        return mini;
    }
};