class Solution {
public:
    vector<vector<char>> board;
    
    bool check (int i, int j, int c) {
        for (int row = 0; row < 9; row++)
            if (board[row][j] == c) return false;
        
        for (int col = 0; col < 9; col++)
            if (board[i][col] == c) return false;
        
        int row = i/3*3;
        int col = j/3*3;
        for (int m = 0; m < 3; m++)
            for (int n = 0; n < 3; n++)
                if (board[row+m][col+n] == c) return false;
        
        return true;
    }
    
    bool recur (int i, int j) {
        if (i == 9) return true;
        if (j == 9) return recur (i+1, 0);
        if (board[i][j] != '.') return recur (i, j+1);
        
        for (char c = '1'; c <= '9'; c++) {
            if (check (i, j, c)) {
                board[i][j] = c;
                if (recur (i, j+1)) return true;
                
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& ret) {
        board = ret;
        recur (0, 0);
        ret = board;
    }
};
