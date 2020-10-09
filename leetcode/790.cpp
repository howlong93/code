class Solution {
   public:
    int numTilings(int N) {
        const int mod = 1000000007;
        vector<long long int> dp(N + 1), keep(N + 1);

        dp[0] = 0, keep[0] = 0;
        dp[1] = 1, keep[1] = 0;
        if (N > 1) dp[2] = 2, keep[2] = 1;
        for (int i = 3; i <= N; i++) {
            dp[i] = (2 * keep[i - 1] + dp[i - 1] + dp[i - 2]) % mod;
            keep[i] = (dp[i - 2] + keep[i - 1]) % mod;
        }

        return dp[N] % mod;
    }
};
