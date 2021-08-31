class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int l = 0, r = nums.size()-1;
        if (nums[0] < nums[1] && nums[0] < nums[r]) return nums[0];
        
        while (l < r) {
            int mid = (l+r-1)/2;
            if (nums[l] < nums[r]) return nums[l];
            
            if (nums[mid] > nums[r]) l = mid+1;
            else r = mid;
        }
        
        return nums[l];
    }
};
