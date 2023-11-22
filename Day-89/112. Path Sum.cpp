class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root== NULL){
            return false;
        }

        if( root->left==NULL && root->right==NULL){
            return targetSum == root->val;
        }

        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};



//or



class Solution {
    void helper(TreeNode* root, int targetSum,bool &ans){
        if(root == NULL){
            return;
        }

        targetSum = targetSum - root->val;

        if(targetSum== 0 && root->left==NULL && root->right==NULL){
            ans = true;
        }

        helper(root->left,targetSum,ans);
        helper(root->right,targetSum,ans);

        // return ans;

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       bool ans = false;
       helper(root,targetSum,ans);
       return ans;
    }
};


//or




class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root== NULL){
            return false;
        }

        targetSum = targetSum - root->val;

        if(targetSum== 0 && root->left==NULL && root->right==NULL){
            return true;
        }

        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
    }
};





//or




class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root== NULL){
            return false;
        }

        targetSum = targetSum - root->val;

        if(targetSum== 0 && root->left==NULL && root->right==NULL){
            return true;
        }

        bool l = hasPathSum(root->left,targetSum);
        bool r = hasPathSum(root->right,targetSum);

        return l || r;
    }
};