class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>values(nums.begin(),nums.end());
        int longest=0;
        for(int val:values){
            if(values.count(val-1)) continue;
        
        int currentlength=1;
        int nextvalue=val+1;
        while(values.count(nextvalue)){
            currentlength++;
            nextvalue++;
        }
        longest=max(longest,currentlength);
        }
        return longest;
    }
};