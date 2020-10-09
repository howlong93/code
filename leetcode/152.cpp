class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        int ans = -2147483647;

        if (nums.size()) dp[0][0] = dp[0][1] = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            dp[i][0] =
                max({dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i], nums[i]});
            dp[i][1] =
                min({dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i], nums[i]});
        }

        for (size_t i = 0; i < nums.size(); i++)
            ans = max({ans, dp[i][0], dp[i][1]});

        return ans;
    }
};
