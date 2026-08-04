class Solution {
public:
    int findMin(vector<int>& nums) {
        int minval=INT_MAX;
        for(int i=0;i<nums.size();i++){
            minval=min(minval,nums[i]);
        }
        return minval;
    }
};