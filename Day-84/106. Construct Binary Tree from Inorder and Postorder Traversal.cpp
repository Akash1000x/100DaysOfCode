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


     TreeNode*helper(vector<int>& postorder, vector<int>& inorder,int size,int &postIndex,int inorderStart,int inorderEnd,unordered_map<int,int> &mapping){
        //base case
        if(postIndex < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        
        int element = postorder[postIndex--];

        TreeNode*root = new TreeNode(element);

        int p = mapping[element];

        root->right = helper(postorder,inorder,size,postIndex,p+1,inorderEnd,mapping);

        root->left = helper(postorder,inorder,size,postIndex,inorderStart,p-1,mapping);
        

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postIndex = size-1;
        int inorderStart = 0;
        int inorderEnd = size-1;

        unordered_map<int,int> mapping;
        for(int i = 0;i<size;i++){
            mapping[inorder[i]] = i;
        }
        
        return  helper(postorder,inorder,size,postIndex,inorderStart,inorderEnd,mapping);
        
    }
};