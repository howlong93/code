class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto k : nums) sum += k;

        if (sum % 2) return false;
        sum /= 2;

        vector<int> dp = vector<int>(sum + 1, 0);
        dp[0] = true;

        for (auto k : nums) {
            for (int i = sum; i >= k; i--) {
                dp[i] = dp[i - k] || dp[i];
            }
        }

        return dp[sum];
    }
};
