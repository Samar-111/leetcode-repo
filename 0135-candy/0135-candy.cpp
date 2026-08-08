class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int candies=n;
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
            i++;
            continue;
        }
        int peak=0;
        while(i<n && ratings[i]>ratings[i-1]){
            peak++;
            candies+=peak;
            i++;
        }
        int vally=0;
        while(i<n && ratings[i]<ratings[i-1]){
            vally++;
            candies+=vally;
            i++;
        }
        candies-=min(peak,vally);
        }
        return candies;
    }
};