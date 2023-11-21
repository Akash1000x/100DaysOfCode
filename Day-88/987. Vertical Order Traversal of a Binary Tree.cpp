/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void helper(TreeNode* root,map<int,map<int,vector<int>>> &mp,int row,int col){
        if(root== NULL){
            return ;
        }

        mp[col][row].push_back(root->val);

        helper(root->left,mp,row+1,col -1);

        helper(root->right ,mp,row+1,col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;//colMap
        
        helper(root,mp,0,0);

        vector<vector<int>> ans;
        //storing answer in ans vector form mp
        for(auto rowMap : mp){
            
            vector<int> v;
           for(auto lvlMap:rowMap.second){
               auto&arr = lvlMap.second;            
                sort(arr.begin(),arr.end());
                for(auto value:arr){
                    v.push_back(value);
                }
                
           }
           ans.push_back(v);
        }

        return ans;
    }
};