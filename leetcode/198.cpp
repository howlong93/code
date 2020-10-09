class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> d(nums.size() + 1);
        d[0] = 0;
        for (size_t i = 1; i <= nums.size(); i++) {
            if (i == 1)
                d[i] = nums[i - 1];
            else
                d[i] = max(d[i - 2] + nums[i - 1], d[i - 1]);
        }

        return d[nums.size()];
    }
};
