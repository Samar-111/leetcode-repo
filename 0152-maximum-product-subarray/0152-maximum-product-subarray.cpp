class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        long long maxproduct = nums[0];

        for (int i = 0; i < n; i++) {
            long long product = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];

                maxproduct = max(maxproduct, product);
            }
        }

        return maxproduct;
    }
};