class NumArray {
   public:
    vector<int> bit;
    int lnth;

    void add(int pos, int val) {
        while (pos <= lnth) {
            bit[pos] += val;
            pos += pos & (-pos);
        }
    }

    int psum(int pos) {
        int ans = 0;
        while (pos > 0) {
            ans += bit[pos];
            pos -= pos & (-pos);
        }
        return ans;
    }

    NumArray(vector<int>& nums) {
        bit = vector<int>(nums.size() + 1, 0);
        lnth = bit.size() - 1;
        for (int i = 0; i < nums.size(); i++) add(i + 1, nums[i]);
    }

    int sumRange(int left, int right) {
        return psum(right + 1) - psum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
