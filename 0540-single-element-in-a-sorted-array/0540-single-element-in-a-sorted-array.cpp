class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorres=0;
        for(int val : nums){
            xorres=xorres^val;
        }
        return xorres;
        
    }
};