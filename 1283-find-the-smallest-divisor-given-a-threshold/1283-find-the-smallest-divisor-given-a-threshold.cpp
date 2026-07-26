class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold)
        return -1;
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
            while(low<=high){
                int mid=(low+high)/2;
                int sum=0;
                for(int num : nums ){
                    sum +=ceil((double)num/mid);

                }
                if(sum<=threshold){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return low;
    }
      
        
    
};