class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>kp;
       for(int i=0;i<nums.size();i++){
        int need=target-nums[i];
        if(kp.find(need)!=kp.end()){
            return {kp[need],i};

        }
         kp[nums[i]]=i;
       }
       return{};
    }
};