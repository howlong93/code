class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0, ret = 0, sz = nums.size();
        long long cur = 1;
        
        while (i < sz && cur <= n) {
            if (nums[i] > cur) {
                cur += cur;
                ret++;
            }
            else cur += nums[i++];
        }
        
        while (cur <= n) cur += cur, ret++;
        
        return ret;
    }
};
