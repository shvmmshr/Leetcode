class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i:gain){
            sum+=i;
            maxi=max(maxi,sum);
        }
        if(maxi<0) return 0;
        return maxi;
    }
};