class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int ans = -2147483647;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }

        for (size_t i = 0; i < nums.size(); i++) {
            ans = max(dp[i], ans);
        }

        return ans;
    }
};
