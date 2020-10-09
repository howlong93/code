class Solution {
   public:
    int ln, lll = 0;
    vector<bool> vis;
    int regionsBySlashes(vector<string>& grid) {
        ln = grid.size();
        vector<vector<int>> pnt(ln * ln * 4);
        int cnt = 0;

        vis.resize(ln * ln * 4);
        fill(vis.begin(), vis.end(), false);

        build(pnt, 0, 0, grid);
        fill(vis.begin(), vis.end(), false);
        cout << lll << '\n';

        for (int i = 0; i < ln * ln * 4; i++) {
            if (vis[i]) continue;

            vis[i] = true;
            cnt++;
            queue<int> q;
            q.push(i);
            while (q.size()) {
                int m = q.front();
                q.pop();
                for (auto k : pnt[m]) {
                    if (!vis[k]) {
                        vis[k] = true;
                        q.push(k);
                    }
                }
            }
        }
        return cnt;
    }
    void build(vector<vector<int>>& pnt, int i, int j, vector<string> grid) {
        if (pos(i, j, 0) < 0 || vis[pos(i, j, 0)]) return;
        lll++;

        vis[pos(i, j, 0)] = true;
        int keep;
        if ((keep = pos(i, j + 1, 0)) >= 0) {
            pnt[pos(i, j, 2)].emplace_back(keep);
            pnt[keep].emplace_back(pos(i, j, 2));
            build(pnt, i, j + 1, grid);
        }

        if ((keep = pos(i + 1, j, 1)) >= 0) {
            pnt[pos(i, j, 3)].emplace_back(keep);
            pnt[keep].emplace_back(pos(i, j, 3));
            build(pnt, i + 1, j, grid);
        }

        if (grid[i][j] == '\\') {
            pnt[pos(i, j, 1)].emplace_back(pos(i, j, 2));
            pnt[pos(i, j, 2)].emplace_back(pos(i, j, 1));
            pnt[pos(i, j, 0)].emplace_back(pos(i, j, 3));
            pnt[pos(i, j, 3)].emplace_back(pos(i, j, 0));
        } else if (grid[i][j] == '/') {
            pnt[pos(i, j, 0)].emplace_back(pos(i, j, 1));
            pnt[pos(i, j, 1)].emplace_back(pos(i, j, 0));
            pnt[pos(i, j, 2)].emplace_back(pos(i, j, 3));
            pnt[pos(i, j, 3)].emplace_back(pos(i, j, 2));
        } else {
            pnt[pos(i, j, 0)].emplace_back(pos(i, j, 1));
            pnt[pos(i, j, 1)].emplace_back(pos(i, j, 0));
            pnt[pos(i, j, 1)].emplace_back(pos(i, j, 2));
            pnt[pos(i, j, 2)].emplace_back(pos(i, j, 1));
            pnt[pos(i, j, 3)].emplace_back(pos(i, j, 2));
            pnt[pos(i, j, 2)].emplace_back(pos(i, j, 3));
            pnt[pos(i, j, 3)].emplace_back(pos(i, j, 0));
            pnt[pos(i, j, 0)].emplace_back(pos(i, j, 3));
        }
    }
    int pos(int i, int j, int s) {
        if (i >= ln || i < 0 || j >= ln || j < 0) return -1;
        return (i * ln + j) * 4 + s;
    }
};
