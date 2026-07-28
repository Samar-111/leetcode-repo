class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>prefixsumcount;
       int prefixsum=0;
       int count=0;
       prefixsumcount[0]=1;
       for(int i=0;i<n;i++){
        prefixsum+=nums[i];
        int remove=prefixsum-k;
        if(prefixsumcount.find(remove)!=prefixsumcount.end()){
            count+=prefixsumcount[remove];
        }
        prefixsumcount[prefixsum]++;
       }
       return count;

        
    }
};