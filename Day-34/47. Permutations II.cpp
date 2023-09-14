class Solution {
public:
 void solve(vector<int>& nums,vector<vector<int>> &ans,int i){
        if(i>= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int,bool> visited;
        for(int j = i;j<nums.size();j++){
            if(visited[nums[j]] == true){
                continue;
            }
            visited[nums[j]] = true;
            swap(nums[i],nums[j]);

            solve(nums,ans,i+1);
            
            swap(nums[i],nums[j]);

            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        solve(nums,ans,i);
        // set<vector<int>> temp2;
        // for(auto a:ans){
        //     temp2.insert(a);
        // }
        // ans.clear();
        // for(auto a : temp2){
        //     ans.push_back(a);
        // }
        return ans;      
    }
};