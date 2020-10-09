class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> pre_sum;
        map<int, int> cnt;

        pre_sum.emplace_back(0);
        for (size_t i = 0; i < nums.size(); i++)
            pre_sum.emplace_back(pre_sum[i] + nums[i]);

        for (auto K : pre_sum) {
            ans += cnt[K - k];
            cnt[K]++;
        }

        return ans;
    }
};
