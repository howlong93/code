class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;

        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }

    void dfs(size_t i, size_t j, vector<vector<char>>& grid) {
        if (grid[i][j] == '0')
            return;
        else {
            grid[i][j] = '0';
            if (i < grid.size() - 1) dfs(i + 1, j, grid);
            if (i > 0) dfs(i - 1, j, grid);
            if (j < grid[i].size() - 1) dfs(i, j + 1, grid);
            if (j > 0) dfs(i, j - 1, grid);
        }
    }
};
