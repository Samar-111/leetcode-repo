class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = 1;
            }
        }

       
        for (long ind = 1; ind < n; ind++) {
            for (long target = 0; target <= amount; target++) {
                long long nottaken = dp[ind - 1][target];
                long long taken = 0;

                if (coins[ind] <= target) {
                    taken = dp[ind][target - coins[ind]];
                }

                dp[ind][target] = nottaken + taken;
            }
        }

        return dp[n - 1][amount];
    }
};