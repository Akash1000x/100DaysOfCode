class Solution {
public:
    void solve(vector<int>& arr,int target,vector<vector<int>> &ans,vector<int> &temp,int index){
        
        //base case
        if(target == 0 ){
            ans.push_back(temp);
            return;
        }
        
        if(target < 0){
           
            return;
        }
        //recursive case
        for(int i = index; i<arr.size();i++){
            //include
            temp.push_back(arr[i]);

            //recursive call
            solve(arr,target-arr[i],ans,temp,i);

            //backtracking
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> temp;
        
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};