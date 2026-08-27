class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }

        if (totalsum % 2 != 0) {
            return false;
        }

        int targetsum = totalsum / 2;

        vector<vector<bool>> dp(n, vector<bool>(targetsum + 1, false));

        
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        
        if (nums[0] <= targetsum) {
            dp[0][nums[0]] = true;
        }

        
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= targetsum; target++) {

                bool nottaken = dp[ind - 1][target];

                bool taken = false;

                if (nums[ind] <= target) {
                    taken = dp[ind - 1][target - nums[ind]];
                }

                dp[ind][target] = nottaken || taken;
            }
        }

        return dp[n - 1][targetsum];
    }
};