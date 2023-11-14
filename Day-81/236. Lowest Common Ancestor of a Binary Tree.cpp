/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == p->val)
            return p;
        if(root->val == q->val)
            return q;

        TreeNode* leftNode = lowestCommonAncestor(root->left,p,q);
        
        TreeNode* rightNode = lowestCommonAncestor(root->right,p,q);

        if(leftNode == NULL && rightNode == NULL)
            return NULL;
        else if(leftNode != NULL && rightNode == NULL)
            return leftNode;
        else if(leftNode == NULL && rightNode != NULL)
            return rightNode;
        else
            return root;
    }
};