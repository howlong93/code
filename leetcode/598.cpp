class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) return m*n;
        int x = 100000, y = 100000;
        for (int i = 0; i < ops.size(); i++) x = min(x, ops[i][0]), y = min (y, ops[i][1]);
        
        return x*y;
    }
};
