class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> cnt_row, cnt_col;
            cnt_row = cnt_col = vector<int>(9, 0);

            for (int j = 0; j < 9; j++) {
                char tmp_col = board[i][j];
                if (tmp_col != '.' && cnt_col[tmp_col - '1'] > 0)
                    return false;
                else if (tmp_col != '.')
                    cnt_col[tmp_col - '1']++;

                char tmp_row = board[j][i];
                if (tmp_row != '.' && cnt_row[tmp_row - '1'] > 0)
                    return false;
                else if (tmp_row != '.')
                    cnt_row[tmp_row - '1']++;
            }
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                vector<int> cnt(9, 0);

                for (int row = 3 * i; row < 3 * i + 3; row++)
                    for (int col = 3 * j; col < 3 * j + 3; col++) {
                        char tmp = board[row][col];

                        if (tmp != '.' && cnt[tmp - '1'] > 0)
                            return false;
                        else if (tmp != '.')
                            cnt[tmp - '1']++;
                    }
            }

        return true;
    }
};
