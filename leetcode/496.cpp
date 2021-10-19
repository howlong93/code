class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> save;
        stack<int> tmp;

        for (auto k : nums2) {
            while (tmp.size() && tmp.top() < k) {
                save[tmp.top()] = k;
                tmp.pop();
            }
            tmp.push(k);
        }

        vector<int> ret(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            if (save.find(nums1[i]) != save.end()) ret[i] = save[nums1[i]];
        }

        return ret;
    }
};
