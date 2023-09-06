class Solution {
public:

    bool isSafe(vector<vector<char>> &NQueens,int row,int n,int col){

        int i = row;
        int j = col;

        while(j>=0){
            if(NQueens[i][j]== 'Q'){
                return false;
            }
            j--;
        }

        i = row;
        j= col;

        while(i>=0 && j>=0){
            if(NQueens[i][j]== 'Q'){
                return false;
            }
            i--;
            j--;
        }

        i = row;
        j = col;

        while(i<n && j>=0){
            if(NQueens[i][j]== 'Q'){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

        void solve(vector<vector<char>> &NQueens,int n,int col,int &count){
        //base case
        if(col>=n){
            count++;
            return;
        }

        //solve 1 case baki redurison dekh lega
        for(int i = 0;i<n;i++){

            if(isSafe(NQueens,i,n,col)){
                
                NQueens[i][col] = 'Q';

                //recurisive call
                solve(NQueens,n,col+1,count);

                //backtrack
                NQueens[i][col] = '.';
            }

        }


    }

    int totalNQueens(int n) {
        vector<vector<char>> NQueens(n,vector<char>(n,'.'));

        int count =0;

        int col = 0;


        solve(NQueens,n,col,count);

        return count;
    }
};