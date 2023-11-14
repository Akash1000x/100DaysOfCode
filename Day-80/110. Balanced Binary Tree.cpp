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
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lheight = helper(root->left);

        int rheight = helper(root->right);

        return max(lheight,rheight) +1;

    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int lheight = helper(root->left);
        int rheight = helper(root->right);

        bool lBalanced = isBalanced(root->left);
        bool rBalanced = isBalanced(root->right);

        if(abs(lheight-rheight) > 1){
            return false;
        }

        return lBalanced && rBalanced;

    }
};