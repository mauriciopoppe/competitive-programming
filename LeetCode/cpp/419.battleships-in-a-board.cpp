class Solution {
    
public:
    int test(vector<vector<char>> &board, int i, int j) {
        if (i < 0 || i == board.size()) return false;
        if (j < 0 || j == board[0].size()) return false;
        return board[i][j] == 'X';
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int total = 0;
        for (int i = 0; i < board.size(); i += 1) {
            for (int j = 0; j < board[0].size(); j += 1) {
                if (board[i][j] == 'X' && !test(board, i - 1, j) && !test(board, i, j - 1)) {
                    total++;
                }
            }
        }
        return total;
    }
};
