class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp,int index ){
        if(target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = index;i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);

            solve(candidates,target -candidates[i],ans,temp,i+1 );

            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        solve(candidates,target,ans,temp,index);
        return ans;
    }
};

// time complexity: O(2^n)
// space complexity: O(n)