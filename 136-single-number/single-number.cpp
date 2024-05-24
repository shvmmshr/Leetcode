class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len=nums.size();
        int c=0;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(nums[i]==nums[j] ){
                    c+=1;
                }
            }
            if(c==1){
                return nums[i];
            }
            c=0;
        }
        return -1;
    }
};