class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char number) {
         
        for (int i = 0; i < 9; i++) {
            //row check
            if (board[i][col] == number ) {
                return false;
            }
            //column check
            if (board[row][i] == number) {
                return false;
            }
        }
        
        // for check 3*3 box
        int boxStartRow  = 3 * (row / 3);
        int boxStartCol  = 3 * (col / 3);
        for (int r = boxStartRow; r < 3+boxStartRow; r++) {
            for (int c = boxStartCol; c < 3+boxStartCol; c++) {
                if (board[r][c] == number) {
                    return false;
                }                           
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board) {
        

        for (int i = 0; i < board.size(); i++) {
            for(int j = 0;j<board.size();j++){
                // Check for empty cell
                if (board[i][j] == '.') {
                    for (char n = '1'; n <= '9'; n++) {
                        // Check for safety 
                        if (isSafe(board, i, j, n)){
                            // insert if safe
                            board[i][j] = n ;
                            // Recursion will handle
                            if(helper(board))
                                return true;                            
                            // Backtracking if solution not found
                            board[i][j] = '.';

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        helper(board);
    }
};
