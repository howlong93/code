class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans (2, 0);
        auto bef = lower_bound (nums.begin(), nums.end(), target);
        auto aft = upper_bound (nums.begin(), nums.end(), target);
        if (bef == nums.end() || *bef != target) ans[0] = ans[1] = -1;
        else ans[0] = bef-nums.begin(), ans[1] = aft-nums.begin()-1;
        return ans;
    }
};
