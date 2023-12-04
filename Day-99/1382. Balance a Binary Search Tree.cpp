class Solution {
    TreeNode* constructTreeByInOrder(vector<int> &v,int s,int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    int element = v[mid];
    TreeNode*root = new TreeNode(element);

    root->left = constructTreeByInOrder(v,s,mid-1);
    root->right = constructTreeByInOrder(v,mid+1,e);
    return root;

}

    void inorderTraversal(TreeNode* root,vector<int>&v){
    // base case
    if(root == NULL){
        return;
    }
    // Left 
    inorderTraversal(root->left,v);
    // Node
    v.push_back(root->val);
    // Right
    inorderTraversal(root->right,v);
}

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorderTraversal(root,v);

        return constructTreeByInOrder(v,0,v.size()-1);

    }
};