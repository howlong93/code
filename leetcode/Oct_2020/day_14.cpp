class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size() - 1), dp_1(nums.size() - 1);

        dp[0] = nums[0];
        if (nums.size() - 1 > 1) dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        if (nums.size() > 1) dp_1[0] = nums[1];
        if (nums.size() > 2) dp_1[1] = max(nums[2], nums[1]);
        for (int i = 2; i < nums.size() - 1; i++) {
            dp_1[i] = max(dp_1[i - 1], dp_1[i - 2] + nums[i + 1]);
        }

        for (auto k : dp) cout << k << ' ';
        cout << '\n';
        for (auto k : dp_1) cout << k << ' ';
        cout << '\n';
        return max(dp[dp.size() - 1], dp_1[dp_1.size() - 1]);
    }
};
