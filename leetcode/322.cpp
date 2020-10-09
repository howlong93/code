class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int> dp(amount + 1, 1e9);
        dp[0] = 0;

        for (long long int i = 0; i <= amount; i++) {
            for (auto k : coins) {
                if (i + k <= amount) {
                    dp[i + k] = min(dp[i + k], dp[i] + 1);
                }
            }
        }

        return (dp[amount] == 1e9) ? -1 : dp[amount];
    }
};
