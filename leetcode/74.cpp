class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rr, rl, cr, cl, kr;
        rl = 0, rr = matrix.size()-1;
        if (!matrix.empty()) cl = 0, cr = matrix[0].size()-1;
        
        while (rl < rr) {
            int mid = (rl + rr) /2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) rl = mid+1;
            else if (matrix[mid][0] > target) rr = mid-1;
        }
        cout << rl << '\n';
        
        while (cl <= cr) {
            int mid = (cl + cr) /2;
            if (matrix[rl][mid] == target) return true;
            else if (matrix[rl][mid] < target) cl = mid+1;
            else cr = mid-1;
        }
        
        return false;
    }
};
