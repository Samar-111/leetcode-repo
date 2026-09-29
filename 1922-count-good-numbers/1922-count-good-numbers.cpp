class Solution {
public:

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;

        while (exp > 0) {

            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }

            base = (base * base) % mod;
            exp = exp / 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long MOD = 1000000007;

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long ans = power(5, evenPositions, MOD)
                      * power(4, oddPositions, MOD);

        return ans % MOD;
    }
};