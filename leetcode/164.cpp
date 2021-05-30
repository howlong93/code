class Solution {
   public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(nums[i + 1] - nums[i], ans);
        }

        return ans;
    }
};
