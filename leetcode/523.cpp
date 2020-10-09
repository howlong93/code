class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int32_t> pre_sum;
        map<int, int> cnt;

        pre_sum.emplace_back(0);
        if (k != 0) {
            for (size_t i = 0; i < nums.size(); i++)
                pre_sum.emplace_back((pre_sum[i] + nums[i]) % k);

            for (size_t i = 0; i < pre_sum.size(); i++) {
                if (cnt[pre_sum[i]] > 0) {
                    if (pre_sum[i] - pre_sum[i - 1] != 0)
                        return true;
                    else if (cnt[pre_sum[i]] > 1)
                        return true;
                }

                cnt[pre_sum[i]]++;
            }
        } else {
            for (size_t i = 0; i < nums.size() - 1; i++) {
                if (nums[i] == 0) {
                    if (nums[i + 1] == 0) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
