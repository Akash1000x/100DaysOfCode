#include<iostream>
#include<vector>
using namespace std;


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



    void storeSolution(vector<vector<char>> &NQueens,int n,vector<vector<string>> &ans){
        vector<string> temp;

        for(int i=0;i<n;i++){
            string output = "";
            for(int j=0;j<n;j++){
                output.push_back(NQueens[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }



    void solve(vector<vector<char>> &NQueens,int n,int col,vector<vector<string>> &ans){
        //base case
        if(col>=n){
            storeSolution(NQueens,n,ans);
            return;
        }

        //solve 1 case baki redurison dekh lega
        for(int i = 0;i<n;i++){

            if(isSafe(NQueens,i,n,col)){
                
                NQueens[i][col] = 'Q';

                //recurisive call
                solve(NQueens,n,col+1,ans);

                //backtrack
                NQueens[i][col] = '.';
            }

        }


    }



    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<char>> NQueens(n,vector<char>(n,'.'));

        vector<vector<string>> ans;

        int col = 0;


        solve(NQueens,n,col,ans);

        return ans;
        
    }
};


//Time complexity  -> O(n!)   or  O(n^n)
//Space complexity -> O(n*m)


//or


// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// //solution by unordered map

// unordered_map<int,bool> rowcheck;
// unordered_map<int,bool> upperLeftDiagonalCheck;
// unordered_map<int,bool> downLeftDiagonalCheck;


// void printSolution(vector<vector<char>> &board,int n){
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout<<board[i][j]<<" ";
//         }
//         cout<<endl;
        
//     }
//     cout<<endl;
    
// }

// void solve(vector<vector<char>> &board,int n,int col){
//     //base case
//     if(col >= n){
//         printSolution(board,n);
//         return;
//     }

//     //1st solve kr lenge baki recurison sambhal lega
//     for (int i = 0; i < n; i++)
//     {
//         if( rowcheck[i]==false && upperLeftDiagonalCheck[col-i] == false && downLeftDiagonalCheck[i+col] == false){

//             board[i][col] = 'Q';
//             rowcheck[i] = true;
//             upperLeftDiagonalCheck[col-i] = true;
//             downLeftDiagonalCheck[i+col] = true;

//             //recurisive call
//             solve(board,n,col+1);
            
//             //backtrack
//             board[i][col] = '-';
//             rowcheck[i] = false;
//             upperLeftDiagonalCheck[col-i] = false;
//             downLeftDiagonalCheck[i+col] = false;
//         }
//     }
    
// }

// int main(){

//     vector<vector<char>> board(4,vector<char>(4,'-'));
    
//     int n = 4;
//     int col = 0;
//     solve(board,n,col);

//     return 0;
// }