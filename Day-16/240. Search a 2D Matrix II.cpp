#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        

        // for(int i= 0;i<row;i++){
            
        //     int start = 0;
        //     int end = col-1;
        //     while(start<=end){

        //         int mid = start + (end-start)/2;
        //         int element = matrix[i][mid];
        //         if(element == target){
        //             return true;
        //         }

        //         else if(element > target){
        //             end = mid -1;
        //         }

        //         else{
        //             start = mid +1;
        //         }

        //     }
            
        // }
        // return false;

        int rowIndex = 0;
        int colIndex = col-1;
        while( rowIndex < row && colIndex >=0 ){
            
            if(matrix[rowIndex][colIndex] == target){
                return true;
            }
            else if(matrix[rowIndex][colIndex] < target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return false;
    }
};