class Solution {
    public:
    int daysneeded(vector<int>& weights, int capacity){
        int days=1;
        int currload=0;
        for(int w: weights){
            if(currload+w>capacity){
                days++;
                currload=w;
            }
            else{
                currload+=w;
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left =*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
        while(left<right){
            int mid=left+(right-left)/2;
            int needed = daysneeded(weights,mid);
            if(needed<=days){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};