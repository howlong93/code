class Solution {
   public:
    int cross(vector<int> a, vector<int> b, vector<int> c) {
        vector<int> m(2), n(2);
        m[0] = b[0] - a[0], m[1] = b[1] - a[1];
        n[0] = c[0] - a[0], n[1] = c[1] - a[1];

        return m[0] * n[1] - m[1] * n[0];
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> convex;
        int n = trees.size(), m = 0;
        sort(trees.begin(), trees.end());

        for (int i = 0; i < n; i++) {
            while (m >= 2 && cross(trees[i], convex[m - 1], convex[m - 2]) < 0)
                convex.pop_back(), m--;
            convex.emplace_back(trees[i]), m++;
        }

        for (int i = n - 2; i >= 0; i--) {
            while (m >= 2 && cross(trees[i], convex[m - 1], convex[m - 2]) < 0)
                convex.pop_back(), m--;
            convex.emplace_back(trees[i]), m++;
        }

        set<vector<int>> tmp;
        for (auto k : convex) tmp.insert(k);
        vector<vector<int>> ret;
        for (auto k : tmp) ret.push_back(k);

        return ret;
    }
};
