class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), ans(nums.size(), 1);
        int ret = 0, keep = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[i] == dp[j] + 1)
                    ans[i] = ans[i] + ans[j];
                else if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans[i] = ans[j];
                }
            }
        }

        for (size_t i = 0; i < nums.size(); i++) {
            cout << dp[i] << ' ' << ans[i] << ' ';
            if (keep == 0) {
                ret = ans[i];
                keep = dp[i];
            } else if (dp[i] > keep) {
                keep = dp[i];
                ret = ans[i];
            } else if (dp[i] == keep)
                ret += ans[i];
            cout << ret << '\n';
        }

        return ret;
    }
}
