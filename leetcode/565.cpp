class Solution {
   public:
    vector<int> sz, par;
    int fnd_root(int x) {
        if (x == par[x]) return x;
        return par[x] = fnd_root(par[x]);
    }

    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        sz = par = vector<int>(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) par[i] = i;

        for (int i = 0; i < nums.size(); i++) {
            int pa = fnd_root(i);
            int pb = fnd_root(nums[i]);

            if (pa != pb) {
                par[pa] = pb;
                sz[pb] += sz[pa];
            }
            ans = max({ans, sz[pa], sz[pb]});
        }

        return ans;
    }
};
