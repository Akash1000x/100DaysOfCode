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
    void helper(TreeNode* &root, int targetSum,vector<vector<int>> &ans,vector<int> &path){
        if(root == NULL){
            return ;
        }

        targetSum = targetSum - root->val;
        path.push_back(root->val);
        
        //path found
        if(targetSum == 0 && root->left == NULL && root->right == NULL){
            ans.push_back(path);    
        }
      
        helper(root->left,targetSum,ans,path);
        helper(root->right,targetSum,ans,path);
        //backtrack
        path.pop_back();      

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root,targetSum,ans,path);
        return ans;


    }
};