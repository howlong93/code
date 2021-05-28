class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        if (nums.size() == 0) return 0;

        for (size_t i = 1; i < nums.size();) {
            if (nums[i] != nums[i - 1])
                cnt++, i++;
            else
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
        }

        return cnt;
    }
};
