class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<bool>> ifv;
    queue<pair<int, int>> q;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        ans.resize(matrix.size());
        ifv.resize(matrix.size());
        for (size_t i = 0; i < matrix.size(); i++) {
            ans[i].resize(matrix[i].size());
            ifv[i].resize(matrix[i].size());
        }

        for (size_t i = 0; i < matrix.size(); i++)
            for (size_t j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == 0) {
                    // cout << i << ' ' << j <<'\n';
                    pair<int, int> keep = make_pair(i, j);
                    ifv[i][j] = true;
                    ans[i][j] = 0;
                    q.push(keep);
                }

        while (q.size()) {
            pair<int, int> k = q.front(), m;
            q.pop();
            if (build(k.first + 1, k.second, ans[k.first][k.second])) {
                m = make_pair(k.first + 1, k.second);
                q.push(m);
            }
            if (build(k.first - 1, k.second, ans[k.first][k.second])) {
                m = make_pair(k.first - 1, k.second);
                q.push(m);
            }
            if (build(k.first, k.second + 1, ans[k.first][k.second])) {
                m = make_pair(k.first, k.second + 1);
                q.push(m);
            }
            if (build(k.first, k.second - 1, ans[k.first][k.second])) {
                m = make_pair(k.first, k.second - 1);
                q.push(m);
            }
        }

        return ans;
    }

    bool build(int i, int j, int rec) {
        if (i >= ans.size() || i < 0 || j >= ans[i].size() || j < 0)
            return false;
        if (ifv[i][j]) return false;
        ifv[i][j] = true;
        ans[i][j] = rec + 1;

        return true;
    }
};
