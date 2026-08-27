class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        int totalsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalsum += nums[i];
        }

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());
        vector<vector<int>> leftSums(n + 1);
        vector<vector<int>> rightSums(n + 1);

        // Generate all subsets of left half
        for (int mask = 0; mask < (1 << n); mask++) {

            int sum = 0;
            int count = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    sum += left[i];
                    count++;
                }
            }

            leftSums[count].push_back(sum);
        }

        
        for (int mask = 0; mask < (1 << n); mask++) {

            int sum = 0;
            int count = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    sum += right[i];
                    count++;
                }
            }

            rightSums[count].push_back(sum);
        }

     
        for (int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int mini = 1e9;

 
        for (int i = 0; i <= n; i++) {

            int need = n - i;

            for (int leftSum : leftSums[i]) {

                double target =
                    (double)(totalsum - 2 * leftSum) / 2.0;

                auto it = lower_bound(
                    rightSums[need].begin(),
                    rightSums[need].end(),
                    target
                );
                if (it != rightSums[need].end()) {

                    int rightSum = *it;

                    int selectedSum = leftSum + rightSum;

                    int diff = abs(totalsum - 2 * selectedSum);

                    mini = min(mini, diff);
                }
                if (it != rightSums[need].begin()) {

                    --it;

                    int rightSum = *it;

                    int selectedSum = leftSum + rightSum;

                    int diff = abs(totalsum - 2 * selectedSum);

                    mini = min(mini, diff);
                }
            }
        }

        return mini;
    }
};