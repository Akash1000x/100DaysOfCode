class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char number) {
         
        for (int i = 0; i < 9; i++) {
            //row check
            if (board[i][col] == number && i !=row) {
                return false;
            }
            //column check
            if (board[row][i] == number && i != col) {
                return false;
            }
        }
        
        // for check 3*3 box
        int boxStartRow  = 3 * (row / 3);
        int boxStartCol  = 3 * (col / 3);
        for (int r = boxStartRow; r < 3+boxStartRow; r++) {
            for (int c = boxStartCol; c < 3+boxStartCol; c++) {
                if (board[r][c] == number && r !=row && c != col) {
                    return false;
                }                           
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board) {
        

        for (int i = 0; i < board.size(); i++) {
            for(int j = 0;j<board.size();j++){
            
                if (board[i][j] != '.') {
                    
                    char n = board[i][j];
                    if (isSafe(board, i, j, n)== false){
                        
                        return false;

                    }
                    
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        return helper(board);

    }
};
