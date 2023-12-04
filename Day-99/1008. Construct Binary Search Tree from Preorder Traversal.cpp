class Solution {

TreeNode* helper(vector<int>&v,int minValue,int maxValue,int&i){
    //base case
   if(i >= v.size()){
        return NULL;
   }

   if(v[i] < minValue || v[i] > maxValue){
       return NULL;
   }
   //create Node
   TreeNode* root = new TreeNode(v[i++]);

   root->left = helper(v,minValue,root->val,i);

   root->right = helper(v,root->val,maxValue,i);

   return root;

}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder,INT_MIN,INT_MAX,i);
    }
};