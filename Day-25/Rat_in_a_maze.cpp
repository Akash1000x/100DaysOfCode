#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i,int j,int row,int col,int arr[][3] ,vector<vector<bool>> &visited){
    
    if(((i>=0 && i<row) && (j>=0 && j<col)) && arr[i][j] ==1 && visited[i][j] == false){
        return true;
    }
    return false;
}

void solveMaze(int arr[][3],int row,int col,int i,int j,vector<vector<bool>> &visited,vector<string> &path,string output){

    //base case
    if(i == row-1  && j == col-1){
        path.push_back(output);
        return;
    }

    //Down -> (i+1,j)
    if(isSafe(i+1,j,row,col,arr,visited)){
        visited[i+1][j] = true;
        solveMaze(arr,row,col,i+1,j,visited,path,output + 'D');
        // Now backtracking
        visited[i+1][j] = false;
    }

    //Left -> (i, j-1)
    if(isSafe(i, j-1,row,col,arr,visited)){
        visited[i][j-1] = true;
        solveMaze(arr,row,col,i, j-1,visited,path,output + 'L');
        // Now backtracking
        visited[i][j-1] = false;
    }

    //Right -> (i,j+1)
    if(isSafe(i,j+1,row,col,arr,visited)){
        visited[i][j+1] = true;
        solveMaze(arr,row,col,i,j+1,visited,path,output + 'R');
        // Now backtracking
        visited[i][j+1] = false;
    }
    
    //Up -> (i-1,j)
        if(isSafe(i-1,j,row,col,arr,visited)){
        visited[i-1][j] = true;
        solveMaze(arr,row,col,i-1,j,visited,path,output + 'U');
        // Now backtracking
        visited[i-1][j] = false;
    }

}

int main(){
    int maze[3][3] = {
        {1,0,0},
        {1,1,0},
        {1,1,1}
    };

    if(maze[0][0] == 0){
        cout<< "No path exists";
        return 0;
    }

    int row = 3;
    int col = 3;
    // Creating a 2D array for visited array
    vector<vector<bool>> visited(row,vector<bool>(col,false));
    // Source value should be 1 as rat is standing on it only
    visited[0][0] = true;
    // Create string which stores all the paths
    vector<string> path;
    string output = "";

    solveMaze(maze,row,col,0,0,visited,path,output);
    for(auto i:path){
        cout<<i<<" ";
    }

    if(path.size() == 0){
        cout<< "No path exists";
    }
    
    return 0;
}


//or

// #include<iostream>
// #include<vector>
// using namespace std;

// int dx[] = {1,0,0,-1};
// int dy[] = {0,-1,1,0};
// char direction[] = {'D','L','R','U'};

// bool isSafe(int i,int j,int row,int col,int arr[][3] ,vector<vector<bool>> &visited){
    
//     if(((i>=0 && i<row) && (j>=0 && j<col)) && arr[i][j] ==1 && visited[i][j] == false){
//         return true;
//     }
//     return false;
// }

// void solveMaze(int arr[][3],int row,int col,int i,int j,vector<vector<bool>> &visited,vector<string> &path,string output){

//     //base case
//     if(i == row-1  && j == col-1){
//         path.push_back(output);
//         return;
//     }

//     for(int k = 0;k<4;k++){

//         int newx = i+dx[k];
//         int newy = j+dy[k];
//         char dir = direction[k];

//         if(isSafe(newx,newy,row,col,arr,visited)){
//             visited[newx][newy] = true;
//             solveMaze(arr,row,col,newx,newy,visited,path,output + dir);
//             // Now backtracking
//             visited[newx][newy] = false;
//         }
        
//     }
// }

// int main(){
//     int maze[3][3] = {
//         {1,0,0},
//         {1,1,0},
//         {1,1,1}
//     };

//     if(maze[0][0] == 0){
//         cout<< "No path exists";
//         return 0;
//     }

//     int row = 3;
//     int col = 3;
//     // Creating a 2D array for visited array
//     vector<vector<bool>> visited(row,vector<bool>(col,false));
//     // Source value should be 1 as rat is standing on it only
//     visited[0][0] = true;
//     // Create string which stores all the paths
//     vector<string> path;
//     string output = "";

//     solveMaze(maze,row,col,0,0,visited,path,output);
//     for(auto i:path){
//         cout<<i<<" ";
//     }

//     if(path.size() == 0){
//         cout<< "No path exists";
//     }
    
//     return 0;
// }