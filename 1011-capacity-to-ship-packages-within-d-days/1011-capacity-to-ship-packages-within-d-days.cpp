class Solution {
    public:
    int daysneeded(vector<int>&weights, int capacity){
        int days=1;
        int currentload=0;
        for(int weight: weights){
            if(currentload+weight>capacity){
                days++;
                currentload=weight;
            }
            else{
                currentload+=weight;
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mincapacity=*max_element(weights.begin(),weights.end());
        int maxcapacity=accumulate(weights.begin(),weights.end(),0);
        int low=mincapacity;
        int high=maxcapacity;
        while(low<high){
            int mid=low+(high-low)/2;
            if(daysneeded(weights,mid)<=days){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};