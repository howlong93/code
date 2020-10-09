class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long int> dp(target + 1, 0);

        for (auto k : nums)
            if (k <= target) dp[k] = 1;

        for (long long int i = 1; i <= target; i++) {
            cout << i << ' ' << dp[i] << '\n';
            for (auto k : nums) {
                if (i + k <= target && INT_MAX - dp[i + k] >= dp[i])
                    dp[i + k] += dp[i];
            }
        }

        return dp[target];
    }
};
