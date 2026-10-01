class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentcount=0;
        int maxcount=0;
        for(int n:nums){
            if(n==1){
                currentcount++;
                maxcount=max(maxcount,currentcount);
            }
            else{
                currentcount=0;
            }
        }
        return maxcount;
        
    }
};