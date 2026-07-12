class Solution {
public:
    int atmostK(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int left=0;
        int count=0;
        for(int right=0;right<nums.size();right++){
            if(freq[nums[right]]==0) k--;
            freq[nums[right]]++;

            while(k<0){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    k++;
                }
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return atmostK(nums,k)-atmostK(nums,k-1);

    }

        

    
};