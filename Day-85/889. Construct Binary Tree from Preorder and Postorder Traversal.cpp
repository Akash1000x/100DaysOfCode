

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/1101431467

class Solution {


     TreeNode*helper(vector<int>& postorder, vector<int>& preorder ,int preStart,int preEnd,int postStart,int postEnd,unordered_map<int,int> &mapping){
        //base case
        if( preStart > preEnd || postStart > postEnd){
            return NULL;
        }
        

        TreeNode*root = new TreeNode(preorder[preStart]);

        if(postStart == postEnd){
            return root;
        }

        int pos = mapping[preorder[preStart+1]];

        int len = pos - postStart + 1 ;

        root->left = helper(postorder,preorder,preStart+1,preStart + len,postStart,pos,mapping);

        root->right = helper(postorder,preorder,preStart+len+1,preEnd,pos+1,postEnd-1,mapping);

        

        return root;

    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder , vector<int>& postorder) {
        int size = preorder.size();
        int preStart = 0;
        int preEnd = size-1;
        int postStart = 0;
        
        int postEnd = size-1;

        unordered_map<int,int> mapping;
        for(int i = 0;i<size;i++){
            mapping[postorder[i]] = i;
        }
        
        return  helper(postorder,preorder ,preStart,preEnd,postStart,postEnd,mapping);
        
    }
};