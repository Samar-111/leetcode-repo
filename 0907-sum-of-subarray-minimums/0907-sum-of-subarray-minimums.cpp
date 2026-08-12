class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && 
                   (i == n || arr[st.top()] >= arr[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

                ans = (ans + 1LL * arr[mid] * left * right) % 1000000007;
            }

            st.push(i);
        }

        return ans;
    }
};